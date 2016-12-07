#include <stdio.h>
#include <math.h>

/* This function computes the product of a lower triangular matrix and a regular dense matrix. It will be used to multiply the
inverse of a diagonal block of L (produced by invert_L.c) by an off-diagonal block of A and thereby solve for an off-diagonal
block of U. The function will be executed on a single processor using OpenMP for parallelization.*/

void LA(float* L, float* A, float* product, int M, int N, int K) {
  // product is MxN
  // L is MxK
  // A is KxN

  // iterate over entries of product
  int i, j ,k;
  for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
      product[i*N+j]=0;  // initialize
     // iterate along row of L/column of A
      for (k=0; k<fmin(i+1,K); k++) {
       product[i*N+j] += L[i*K+k]*A[k*N+j];   // add L[i,k]*A[k,j]
      }
    }
  }
}
