#include <stdio.h>
#include <math.h>

/* This function computes the product of a lower triangular matrix and an upper triangular matrix, and then subtracts that product
from a regular dense matrix. It will be used to update blocks of A after we've solved for a pair of L and U blocks whose product
contributes to that block of A. The function will be executed on a single processor using OpenMP for parallelization.*/

void AmLU(float* A, float* L, float* U, int M, int N, int K) {
  // A is MxN
  // L is MxK
  // U is KxN

  // iterate over entries of A
  int i, j ,k;
  #pragma omp parallel for schedule(guided)
  for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
      // iterate along row of L/column of U
      for (k=0; k<fmin(fmin(i+1,K),j+1); k++) {
       A[i*N+j] -= L[i*K+k]*U[k*N+j];   // subtract L[i,k]*U[k,j]
      }
    }
  }
}
