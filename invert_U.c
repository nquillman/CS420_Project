#include <stdio.h>
#include <math.h>

/* This function computes the inverse of an upper triangular matrix using back substitution. It will be used to invert
the diagnal blocks of U, which is the first step in solving for the off-diagonal blocks of L. The function will be executed
on a single processor using OpenMP for parallelization.*/

int main(double* matrix, double* inverse) {
  double temp_sum=0;
  for(int j=max; j>=0; j--)
  {
      inverse[j][j]=1/matrix[j][j];
      
    for(int i=j-1; i>=0; i--)
      {
        for(int k=j; k>i; k--)
        {temp_sum-=matrx[i][k]*inverse[k][j];}
      
          inverse[i][j]=  temp_sum/matrix[i][i];
      }
          temp_sum=0;
  }
  
  
  return 0;
}
