spmv-omp-phi
============

Implementation of Sparse-Matrix Vector Multiplication (SpMV) in C and OpenMP for highly parallel architectures such as Intel Xeon Phi

Currently supports the following sparse storage formats:
1. CRS aka CSR
2. CCS aka CSC
3. BCRS aka BCSR
4. ELL aka ELLPack format

Desired formats to add support to (no timeline maybe never):
1. COO
2. HYB (COO+ELL)
3. ELL_A similar to ELL except with variable length rows
