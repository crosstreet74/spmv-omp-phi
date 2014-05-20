/*  DENSE MATRIX HEADER FILE  */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
//#include <omp.h>

#include "mmio.h"   /* Acquired from Matrix Market http://math.nist.gov/MatrixMarket/ */
#include "util.h"

#ifndef _dense_h
#define _dense_h

typedef struct MATRIX {
	double        **mel;         /*  matrix elements  */
	int nrows;         /*  number of rows  */
	int ncols;         /*  number of columns  */
	int          nnz;           /*  number of non-zero elements, (-1) if unknown  */
} MATRIX;


MATRIX*      ReadMatrix(FILE *file);
int          WriteMatrix(FILE *file, MATRIX *m);
double       DotProduct(const double *a, const double *b, int n);
double*      MultiplyMatrix(MATRIX *m, double *v);
void         PrintMatrix(MATRIX *m);
void         DestroyMatrix(MATRIX *m);

#endif
