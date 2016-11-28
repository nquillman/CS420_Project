#include <stdio.h>
#include <math.h>

/* This function computes the LU decomposition of a matrix block using Guassian elimination. It will be used
to factor the diagonal blocks of the matrix and it will execute on a single processor using OpenMP for parallelization. */

int main(float* matrix, float* inverse) {
  //matrix[i][j]
  float temp_sum=0;
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
  return 0;
}
