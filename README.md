This is a repository for the code for our CS420 group project.
Proposal: https://www.overleaf.com/6844330tfqbfdsqvbtd
Research Plan: https://www.overleaf.com/6921335qcfnvgsyqtbd

Tasks:
  - Email professor to ask about dynamic MPI (Alina)
  - Turn in research plan by Friday (everyone)
  - Develop functions using Open MP over Thanksgiving break
      - LU decomposition (for diagonal A blocks)  -> Alina
      - Invert triangular matrices (for diagonal L and U blocks)  -> Zicheng
          - use forward and back substitution to solve L(L^-1)=I and U(U^-1)=I
      - Two versions of matrix multiplication (to get off-diagonal L and U blocks and update A) -> Nora?
          - optimize for triangular matrix times regular matrix (L^-1 or U^-1 times A)
          - optimize for two triangular matrices (A-LU)
