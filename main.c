#include <mpi.h>

int main(){

  MPI_Init();
  int myrank,size;
  MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  
  if (myrank==0) {
      // master code
  }
  
  else {
      // slave code
  }
}
