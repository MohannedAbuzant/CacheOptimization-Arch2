# CacheOptimization-Arch2
This was a Computer Architecture 2 Homework based on CacheOptimization where we were given the following PDF:
<p align="justify">

# An-Najah	National	University

# Computer	Engineering	Department

## Computer	Architecture II HW	# 3	

## Cache	Optimizations

Matrix multiplication is one of the most important modern computational kernels. In this homework we
will try to optimize this computation using the memory/cache optimization techniques we learnt in the
class.

**Instructions:**

1 - In the source file cache.c you will find the conventional (unoptimized) version of matrix
multiplication implemented in the function **mat_mat(...)**

2 - Define a new function called **mat_mat_interchanged(...)** in which you will implement the
interchange optimization. Make sure to verify the correctness of the output of this function by
comparing with the result of the conventional matrix multiplication function. You can use the **compare**
function for that.

3 - Define a new function called **mat_mat_blocked** in which you will implement the blocking
optimization. Make sure to verify the correctness of the output of this function as above. Experiment
with more than one block size (try 1 6, 32 and 64 for example).

4 - Define a new function called **mat_mat_blocked_interchanged()** in which you will implement both
of the previous optimizations at the same time. Don’t forget to verify the correctness of the output.

5 - In addition to your code make sure to hand a one-page report describing and explaining your results.

```
Good Luck
```

</p>
