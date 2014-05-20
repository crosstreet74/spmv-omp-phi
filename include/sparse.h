/*  SPARSE STORAGE HEADER FILE  */

#include <stdlib.h>
#include <stdio.h>
//#include <omp.h>
//#include <offload.h>

#include "dense.h"

#ifndef _sparse_h
#define _sparse_h


typedef struct CCS {
	int *colPtr;		/*  column pointer  */
	double        *A;            /*  non-zero elements  */
	int *rowInd;		/*  row identifier  */
	int nrows;         /*  original size of rows  */
	int ncols;		    /*  original size of columns  */
	int nnz;		    /*  number of non-zero elements  */
} CCS;

typedef struct CRS {
	int *rowPtr;		/*  row pointer  */
	double        *A;            /*  non-zero elements  */
	int *colInd;		/*  column identifier  */
	int nrows;         /*  original size of rows  */
	int ncols;		    /*  original size of columns  */
	int nnz;		    /*  number of non-zero elements  */
} CRS;


CCS*         CreateCCS(MATRIX *m);
void         PrintCCS(CCS *c);
void         MultiplyCCS(CCS *c, double *v, double* r);
void         DestroyCCS(CCS *c);

CRS*         CreateCRS(MATRIX *m);
void         PrintCRS(CRS *c);
void         MultiplyCRS(CRS *c, double *v, double* r);
void         DestroyCRS(CRS *c);


#endif
