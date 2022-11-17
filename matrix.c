#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#include "matrix.h"
// Helper functions for matrix computation. Works with the matrix struct.

void printm(matrix *m){
    // display a matrix
    for (int i=0; i<m->dims[0]; i++){
        for (int j=0; j<m->dims[1]; j++){
            printf("%f ", m->mat[i][j]);
        }
        printf("\n");
    }

    printf("Dims: %d %d\n\n", m->dims[0], m->dims[1]);
}

matrix *random2(int dims[2]){
    // create a 2d matrix on the heap initialised with random values b/w 0 and 1

    double **ret = (double **)malloc(dims[0]*sizeof(double **));
    #pragma omp parallel for 
    for (int i=0; i<dims[0]; i++){
        double *row = (double *)malloc(dims[1]*sizeof(double));
        for (int j=0; j<dims[1]; j++){
            row[j] = (double)rand()/(double)RAND_MAX;
        }

        ret[i] = row;
    }

    matrix *ret1 = (matrix *)malloc(sizeof(matrix));

    ret1->mat = ret;
    ret1->dims[0] = dims[0];
    ret1->dims[1] = dims[1];

    return ret1;
}

matrix *randrange2(int dims[2], int range[2]){
    // create a 2d matrix on the heap initialised with random values b/w a specified range

    if (range[1] < range[0]){
        printf("Error: invalid range\n\n");
        exit(1);
    }

    double **ret = (double **)malloc(dims[0]*sizeof(double **));

    #pragma omp parallel for
    for (int i=0; i<dims[0]; i++){
        double *row = (double *)malloc(dims[1]*sizeof(double));
        for (int j=0; j<dims[1]; j++){
            row[j] = (double)rand()/(double)RAND_MAX * (range[1] - range[0]) + range[0];
        }

        ret[i] = row;
    }

    matrix *ret1 = (matrix *)malloc(sizeof(matrix));

    ret1->mat = ret;
    ret1->dims[0] = dims[0];
    ret1->dims[1] = dims[1];

    return ret1;
}

matrix *ones2(int dims[2]){
    // create a 2d matrix on the heap initialised with ones

    double **ret = (double **)malloc(dims[0]*sizeof(double **));

    #pragma omp parallel for
    for (int i=0; i<dims[0]; i++){
        double *row = (double *)malloc(dims[1]*sizeof(double));
        for (int j=0; j<dims[1]; j++){
            row[j] = 1;
        }

        ret[i] = row;
    }

    matrix *ret1 = (matrix *)malloc(sizeof(matrix));

    ret1->mat = ret;
    ret1->dims[0] = dims[0];
    ret1->dims[1] = dims[1];

    return ret1;
}

matrix *fill2(int dims[2], int val){
    // create a 2d matrix on the heap initialised with custom

    double **ret = (double **)malloc(dims[0]*sizeof(double **));

    #pragma omp parallel for
    for (int i=0; i<dims[0]; i++){
        double *row = (double *)malloc(dims[1]*sizeof(double));
        for (int j=0; j<dims[1]; j++){
            row[j] = val;
        }

        ret[i] = row;
    }

    matrix *ret1 = (matrix *)malloc(sizeof(matrix));

    ret1->mat = ret;
    ret1->dims[0] = dims[0];
    ret1->dims[1] = dims[1];

    return ret1;
}


matrix *zeros2(int dims[2]){
    // create a 2d matrix on the heap initialised with zeros

    double **ret = (double **)malloc(dims[0]*sizeof(double **));

    #pragma omp parallel for
    for (int i=0; i<dims[0]; i++){
        double *row = (double *)calloc(dims[1], sizeof(double));

        ret[i] = row;
    }

    matrix *ret1 = (matrix *)malloc(sizeof(matrix));

    ret1->mat = ret;
    ret1->dims[0] = dims[0];
    ret1->dims[1] = dims[1];

    return ret1;
}

matrix *alloc2(int dims[2]){
    // create an uninitialised 2d matrix on the heap

    double **ret = (double **)malloc(dims[0]*sizeof(double **));

    #pragma omp parallel for
    for (int i=0; i<dims[0]; i++){
        double *row = (double *)malloc(dims[1]*sizeof(double));

        ret[i] = row;  
    }

    matrix *ret1 = (matrix *)malloc(sizeof(matrix));

    ret1->mat = ret;
    ret1->dims[0] = dims[0];
    ret1->dims[1] = dims[1];

    return ret1;
}

matrix *matmul(matrix *mat1, matrix *mat2){
    // Matrix multiplication

    int R1 = mat1->dims[0], C1 = mat1->dims[1];
    int R2 = mat2->dims[0], C2 = mat2->dims[1];

    if (C1 != R2){
        printf("Error: incompatible dimensions for matmul ({%d %d} and {%d %d})\n\n", R1, C1, R2, C2);
        exit(1);
    }

    int rdims[2] = {R1, C2};
    matrix *rslt = alloc2(rdims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt->mat[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                rslt->mat[i][j] += mat1->mat[i][k] * mat2->mat[k][j];
            }
        }
    }

    return rslt;
}

matrix *mul(double n, matrix *mat1){
    // Scalar multiplication

    double **mat = mat1->mat;
    int *dims = mat1->dims;

    matrix *rslt = alloc2(dims);

    #pragma omp parallel for collapse(2)
    for (int i=0; i<dims[0]; i++){
        for (int j=0; j<dims[1]; j++){
            rslt->mat[i][j] = n*mat[i][j];
        }
    }

    return rslt;
}

matrix *add(matrix *mat1, matrix *mat2){
    // Matrix addition

    int R1 = mat1->dims[0], C1 = mat1->dims[1];
    int R2 = mat2->dims[0], C2 = mat2->dims[1];


    if(R1 != R2 || C1 != C2){
        printf("Error: incompatible dimensions for add ({%d %d} and {%d %d})\n\n", R1, C1, R2, C2);
        exit(1);
    }

    int *dims = mat1->dims;

    matrix *rslt = alloc2(dims);

    #pragma omp parallel for collapse(2)
    for (int i=0; i<dims[0]; i++){
        for (int j=0; j<dims[1]; j++){
            rslt->mat[i][j] = mat1->mat[i][j] + mat2->mat[i][j];
        }
    }

    return rslt;
}

matrix *subtract(matrix *mat1, matrix *mat2){
    // Matrix addition

    int R1 = mat1->dims[0], C1 = mat1->dims[1];
    int R2 = mat2->dims[0], C2 = mat2->dims[1];


    if(R1 != R2 || C1 != C2){
        printf("Error: incompatible dimensions for add ({%d %d} and {%d %d})\n\n", R1, C1, R2, C2);
        exit(1);
    }

    int *dims = mat1->dims;

    matrix *rslt = alloc2(dims);

    #pragma omp parallel for collapse(2)
    for (int i=0; i<dims[0]; i++){
        for (int j=0; j<dims[1]; j++){
            rslt->mat[i][j] = mat1->mat[i][j] - mat2->mat[i][j];
        }
    }

    return rslt;
}

matrix *matrix2(int dims[2], double vals[][dims[1]]) {
    matrix *ans =  alloc2(dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < dims[0]; i++) {
        for (int j = 0; j < dims[1]; j++) {
            ans->mat[i][j] = vals[i][j];
        }
    }
    return ans;
}

void unalloc(matrix *mat) {
    #pragma omp parallel for
    for (int i = 0; i < mat->dims[0]; i++) {
        free(mat->mat[i]);
    }
    free(mat);
}

matrix *identity(int n) {
    matrix *ans =  alloc2((int [2]){n, n});

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans->mat[i][j] = (i == j);
        }
    }
    return ans;
}

matrix *transpose(matrix *mat) {
    matrix *ans = alloc2((int[2]){mat->dims[1], mat->dims[0]});
    for (int i = 0; i < mat->dims[0]; i++) {
        for (int j = 0; j < mat->dims[1]; j++) {
            ans->mat[j][i] = mat->mat[i][j];
        }
    }
    return ans;
}

matrix *broadadd(matrix *mat, double n) {
    matrix *ans = alloc2((int[2]){mat->dims[1], mat->dims[0]});

    for (int i = 0; i < mat->dims[0]; i++) {
        for (int j = 0; j < mat->dims[1]; j++) {
            ans->mat[i][j] = mat->mat[i][j] + n;
        }
    }
    return ans;
}

#define MAX_CSV_BYTES 1000*1000
#define MAX_ROWS 100
#define MAX_COLS 100

matrix *read_csv(char *filename) {
    FILE *fptr = fopen(filename, "r");
    int dims[2] = {0, 0};

    if (!fptr) {
        printf("can't open file");
        return zeros2((int[2]){0, 0});
    } else {
        double vals[MAX_ROWS][MAX_COLS];
        char buffer[MAX_CSV_BYTES];
        int row = 0;
        int column = 0;
        while (fgets(buffer, MAX_CSV_BYTES, fptr)) {
            column = 0;
            char *value = strtok(buffer, ",");
            double num;
            while (value) {
                num = atof(value);
                vals[row][column] = num;
                value = strtok(NULL, ",");
                column++;
            }
            row++;
        }
        fclose(fptr);
        double vals2[row][column];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                vals2[i][j] = vals[i][j];
            }
        }

        return matrix2(
            (int[2]){row, column},
            vals2
        );
    }
}