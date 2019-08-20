#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mmio.h"
#include "blocked.h"

void usage(int argc, char **argv, char **fileName)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <HB file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        int len = strlen(argv[1]);
        *fileName = (char *)malloc(sizeof(char) * (len + 1));
        strcpy(*fileName, argv[1]);
    }
}

void print_matrix_info(char *fileName, MM_typecode matcode,
                       int m, int n, int nnz)
{
    fprintf(stdout, "-----------------------------------------------------\n");
    fprintf(stdout, "Matrix name:     %s\n", fileName);
    fprintf(stdout, "Matrix size:     %d x %d => %d\n", m, n, nnz);
    fprintf(stdout, "-----------------------------------------------------\n");
    fprintf(stdout, "Is matrix:       %d\n", mm_is_matrix(matcode));
    fprintf(stdout, "Is sparse:       %d\n", mm_is_sparse(matcode));
    fprintf(stdout, "-----------------------------------------------------\n");
    fprintf(stdout, "Is complex:      %d\n", mm_is_complex(matcode));
    fprintf(stdout, "Is real:         %d\n", mm_is_real(matcode));
    fprintf(stdout, "Is integer:      %d\n", mm_is_integer(matcode));
    fprintf(stdout, "Is pattern only: %d\n", mm_is_pattern(matcode));
    fprintf(stdout, "-----------------------------------------------------\n");
    fprintf(stdout, "Is general:      %d\n", mm_is_general(matcode));
    fprintf(stdout, "Is symmetric:    %d\n", mm_is_symmetric(matcode));
    fprintf(stdout, "Is skewed:       %d\n", mm_is_skew(matcode));
    fprintf(stdout, "Is hermitian:    %d\n", mm_is_hermitian(matcode));
    fprintf(stdout, "-----------------------------------------------------\n");
}

void check_mm_ret(int ret)
{
    switch (ret)
    {
    case MM_COULD_NOT_READ_FILE:
        fprintf(stderr, "Error reading file.\n");
        exit(EXIT_FAILURE);
        break;
    case MM_PREMATURE_EOF:
        fprintf(stderr, "Premature EOF (not enough values in a line).\n");
        exit(EXIT_FAILURE);
        break;
    case MM_NOT_MTX:
        fprintf(stderr, "Not Matrix Market format.\n");
        exit(EXIT_FAILURE);
        break;
    case MM_NO_HEADER:
        fprintf(stderr, "No header information.\n");
        exit(EXIT_FAILURE);
        break;
    case MM_UNSUPPORTED_TYPE:
        fprintf(stderr, "Unsupported type (not a matrix).\n");
        exit(EXIT_FAILURE);
        break;
    case MM_LINE_TOO_LONG:
        fprintf(stderr, "Too many values in a line.\n");
        exit(EXIT_FAILURE);
        break;
    case MM_COULD_NOT_WRITE_FILE:
        fprintf(stderr, "Error writing to a file.\n");
        exit(EXIT_FAILURE);
        break;
    case 0:
        fprintf(stdout, "File loaded.\n");
        break;
    default:
        fprintf(stdout, "Error - should not be here.\n");
        exit(EXIT_FAILURE);
        break;
    }
}

void read_info(char *fileName)
{
    FILE *fp;
    MM_typecode matcode;
    int m;
    int n;
    int nnz;

    if ((fp = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", fileName);
    }

    if (mm_read_banner(fp, &matcode) != 0)
    {
        fprintf(stderr, "Error processing Matrix Market banner.\n");
    }
    if (mm_read_mtx_crd_size(fp, &m, &n, &nnz) != 0)
    {
        fprintf(stderr, "Error reading size.\n");
        exit(EXIT_FAILURE);
    }
    print_matrix_info(fileName, matcode, m, n, nnz);

    fclose(fp);
}

int main(int argc, char **argv)
{
    char *fileName;
    usage(argc, argv, &fileName);
    /*
#if DEBUG
    fprintf(stderr, "HB file name: %s\n", fileName);
    read_info(fileName);
#endif
    */
    int ret;
    MM_typecode matcode;
    FILE *fp = fopen(fileName, "r");
    int m;
    int n;
    int nnz;
    int i;
    int *I;
    int *J;
    double *val;
    MATRIX* mtx = ReadMatrix(fp);

    ret = mm_read_mtx_crd(fileName, &m, &n, &nnz, &I, &J, &val, &matcode);
    check_mm_ret(ret);

    /*
#if DEBUG
    fprintf(stdout, "First 10 non-zeros\n");
    for (int i = 0; i < 10; i++)
    {
        fprintf(stdout, "%d %d %g\n", I[i], J[i], val[i]);
    }
    fprintf(stdout, "Last 10 non-zeros\n");
    for (int i = 0; i < 10; i++)
    {
        fprintf(stdout, "%d %d %g\n", I[nnz - 1 - i], J[nnz - 1 - i],
                val[nnz - 1 - i]);
    }
#endif
*/

    free(I);
    free(J);
    free(val);

    return 0;
}
