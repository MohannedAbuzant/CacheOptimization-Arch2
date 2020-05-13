

#include <immintrin.h>  // portable to all x86 compilers
#include <stdio.h>
#include <time.h>

#define DATA float


const int SIZE  = 1024  ;

DATA A[SIZE][SIZE] ;
DATA B[SIZE][SIZE] ;
DATA C[SIZE][SIZE] ;
DATA C2[SIZE][SIZE] ;
DATA C3[SIZE][SIZE] ;

double seconds()
{

  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  return now.tv_sec + now.tv_nsec / 1000000000.0;
}

void initialize_array(DATA a[], int size)
{
	for (int i = 0 ;  i < size ; i++)
	{
		a[i] = rand()%2;
	}
}
void initialize_2d_array(DATA a[SIZE][SIZE])
{
    for (int i = 0 ; i < SIZE ; i++)
        for (int j = 0 ; j < SIZE ; j++)
        {
            a[i][j] = rand()%2;
        }
}

void zero_2d_array(DATA a[SIZE][SIZE])
{
    for (int i = 0 ; i < SIZE ; i++)    
        for (int j = 0 ; j < SIZE ; j++)
        {
            a[i][j] = 0;
        }
}

int compare(DATA A[SIZE][SIZE],DATA B[SIZE][SIZE])
{

    for (int i = 0 ; i < SIZE ; i++)
        for (int j = 0 ; j < SIZE ; j++)
            if ( A[i][j] != B[i][j])
                return 0;

    return 1;
}

void mat_mat(DATA A[SIZE][SIZE], DATA B[SIZE][SIZE],DATA C[SIZE][SIZE]) 
{
    for (int i = 0 ; i < SIZE ; i++)
        for (int j = 0 ; j < SIZE ; j++)
        {
            C[i][j] = 0;

            for (int k = 0 ; k < SIZE ; k++)
                C[i][j]+= A[i][k]*B[k][j];
        }
}

void mat_mat_interchanged(DATA A[SIZE][SIZE], DATA B[SIZE][SIZE],DATA C[SIZE][SIZE]) 
{
    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i< SIZE; i++) {
            
            for (int j= 0; j< SIZE; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
   }
}

void mat_mat_blocked(DATA A[SIZE][SIZE], DATA B[SIZE][SIZE],DATA C[SIZE][SIZE]) 
{
    int  n = 16 ;
    for (int k = 0; k < SIZE; k+=n) {
        for (int i = 0; i < SIZE; i+=n) {
            for (int j = 0; j < SIZE; j+=n) {
                for (int i1 = i; i1 < i + n; i1++) {
                    for(int j1=j;j1<j+n;j1++){
                        for (int k1 = k; k1 < k + n; k1++) {
                            C[i1][j1] += A[i1][k1] * B[k1][j1];
                            
                        }

                    }
              }
                
            }
        }
     }
}

void mat_mat_blocked_interchanged(DATA A[SIZE][SIZE], DATA B[SIZE][SIZE],DATA C[SIZE][SIZE]) 
{

}


int main()
{


	DATA r;
	double before,after;

	initialize_2d_array(A);
	initialize_2d_array(B);


	before = seconds();

	mat_mat(A,B,C);

	after = seconds();

	printf("Conventional Time:%f\n",after-before);


    before = seconds();

    mat_mat_interchanged(A,B,C2);

    after = seconds();

    printf("Interchanged Time:%f\n",after-before);

    printf("verification:%d\n",compare(C,C2));


    
     before = seconds();

    mat_mat_blocked(A,B,C3);

    after = seconds();

    printf("Blocked Time:%f\n",after-before);

    printf("verification:%d\n",compare(C,C3));


/*    
     before = seconds();

    mat_mat_blocked_opt(...,C4);

    after = seconds();

    printf("Blocked Interchanged Time:%f\n",after-before);

    printf("verification:%d\n",compare(C,C4));
*/

    return 0;
}