//
//  reorder.h
//  
//
//  Created by Husain on 11/11/13.
//
//

#include "util.h"

#ifndef _reorder_h
#define _reorder_h

extern int index_gc;

extern int P[20000];     // Holds final permutation of column (indices)

void column_intersection(double** input, double** output, int nrows, int ncols);
void gray_code(double** A, int* C, int rowIndex, int sign, int nrows, int ncols);

#endif
