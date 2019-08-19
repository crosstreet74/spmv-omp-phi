/*  BLOCKED STORAGE HEADER FILE  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "dense.h"
#include "sparse.h"

#ifndef _blocked_h
#define _blocked_h

#ifndef max
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#define NX INT_MAX

typedef struct BCRS {
    int *colInd;
    int *nnzPtr;
    int *rowPtr;
    double *value;
    int nrows;
    int ncols;
    int nnz;
    int nblocks;
} BCRS;


typedef struct ELL {
    double **values;
    int **indices;
    int nrows;
    int ncols;
    int nnz;
    int max_entries_per_row;
} ELL;


BCRS*        CreateBCRS(MATRIX *m);
void         PrintBCRS(BCRS *c);
void         MultiplyBCRS(BCRS *c, double *x, double *result);
void         DestroyBCRS(BCRS *cc);


ELL*         CreateELL(MATRIX *m);
void         PrintELL(ELL *c);
void         MultiplyELL(ELL* e, double* x, double* r);
void         DestroyELL(ELL* c, MATRIX *m);

#endif
