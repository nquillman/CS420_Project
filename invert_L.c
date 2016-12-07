#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This function computes the inverse of a lower triangular matrix using forward substitution. It will be used to invert
the diagnal blocks of L, which is the first step in solving for the off-diagonal blocks of U. The function will be executed
on a single processor using OpenMP for parallelization.*/

void invert_L(double* matrix, double* inverse) {
  //matrix[i][j]
  double temp_sum=0;
  for(int j=0; j<=max;j++)
  {
       inverse[j][j]=1/(matrix[j][j]);
    
      for(int i=j+1; i<=max; i++)
      {
        {
          for(int k=j;k<i;k++)
          {
              temp_sum-=matrix[i][k]*inverse[k][j];
          }
          inverse[i][j]=temp_sum/matrix[i][i];
          
        }
          temp_sum=0;
      }
  }
}
