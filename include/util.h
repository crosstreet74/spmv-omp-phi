/*  UTILITY HEADER FILE  */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#ifndef _util_h
#define _util_h


double       dtime();
double       Random();
void         QuickSort(double *a, int *b, int *c, int beg, int end);
void         swapF(double *a, double *b);
void         swapI(int *a, int *b);

/* USED IN reorder.* */
int          findMax(int* input, int n);
int          exists(int *input, int ncols, int n);

#endif
