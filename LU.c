#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

/* This function computes the LU decomposition of a matrix block using Guassian elimination. It will be used
to factor the diagonal blocks of the matrix and it will execute on a single processor using OpenMP for parallelization.
Assume U is initialized with the value of A. */


void LU(float* L, float* U, int N) {
	
	int i,j,k;
	
	// iterate over columns to be eliminated
	for (k=0; k<N; k++) {
		L[k*N+k]=1;
		
		// eliminate column k in rows i>k
		#pragma omp parallel
		for (i=k+1; i<N; i++) {
			L[i*N+k] = U[i*N+k]/U[k*N+k];
			U[i*N+k] = 0;

			// update row i of U and L
			for (j=k+1; j<N; j++) {
				L[i*N+j] = 0;
				U[i*N+j] -= L[i*N+k] * U[k*N+j];
			}
		}
	}
}
