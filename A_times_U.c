#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This function computes the product of an upper triangular matrix and a regular dense matrix. It will be used to multiply the
inverse of a diagonal block of U (produced by invert_U.c) by an off-diagonal block of A and thereby solve for an off-diagonal
block of L. The function will be executed on a single processor using OpenMP for parallelization.*/

void AU(float* A, float* U, float* product, int M, int N, int K) {
  // product is MxN
  // A is MxK
  // U is KxN

  // iterate over entries of product
  int i, j ,k;
  #pragma omp parallel for schedule(guided)
  for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
      product[i*N+j]=0;  // initialize
      // iterate along row of A/column of U
      for (k=0; k<fmin(j+1,K); k++) {
       product[i*N+j] += A[i*K+k]*U[k*N+j];   // add A[i,k]*U[k,j]
      }
    }
  }
}
