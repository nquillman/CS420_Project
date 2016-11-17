This is a repoository for the code for our CS420 group project.

Tasks:
  - Email professor to ask about dynamic MPI (Alina)
  - Finish and turn in research plan by Friday (everyone)
      - add details about MPI calls
      - add discussion of topology
  - Develop functions using Open MP over Thanksgiving break
      - LU decomposition (for diagonal A blocks)
      - Invert triangular matrices (for diagonal L and U blocks)
          - use forward and back substitution to solve LX=I and UY=I
      - Two versions of matrix multiplication (to get off-diagonal L and U blocks and update A)
          - optimize for triangular matrix times regular matrix (L^-1 or U^-1 times A)
          - optimize for two triangular matrices (A-LU)
