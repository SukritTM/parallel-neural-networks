#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    float **mat;
    int dims[2];
} matrix;

void printm(matrix *m);

matrix *random2(int dims[2]);

matrix *randrange2(int dims[2], int range[2]);

matrix *ones2(int dims[2]);

matrix *fill2(int dims[2], int val);

matrix *zeros2(int dims[2]);

matrix *alloc2(int dims[2]);

matrix *matmul(matrix *mat1, matrix *mat2);

matrix *mul(int n, matrix *mat1);

matrix *add(matrix *mat1, matrix *mat2);

matrix *matrix2(int dims[2], float vals[][dims[1]]);

void unalloc(matrix *mat);

matrix *identity(int n);

matrix *transpose(matrix *mat);

matrix *broadadd(matrix *mat, float n);

#endif