This is a repository for the code for our CS420 group project.

Proposal: https://www.overleaf.com/6844330tfqbfdsqvbtd

Research Plan: https://www.overleaf.com/6921335qcfnvgsyqtbd

Tasks:
  - Email professor to ask about dynamic MPI (Alina)
  - Develop functions using Open MP over Thanksgiving break (see files for more explanation of functions)
      - LU.c: LU decomposition (for diagonal A blocks)  -> Alina
      - invert_L.c and invert_U.c: Invert triangular matrices -> Zicheng
          - use forward and back substitution to solve L(L^-1)=I and U(U^-1)=I
      - L_times_A.c, U_times_A.c, and A_minus_LU.c: Matrix multiplication -> Nora?
          - optimize for triangular matrix times regular matrix (L or U times A)
          - optimize for two triangular matrices (A-LU)
