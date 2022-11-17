#include <stdio.h>
#include <math.h>
#include <omp.h>
#include "matrix.h"

double func_linear(double n) {
    return n;
}

matrix *activation_linear(matrix *A) {
    matrix *ans = alloc2(A->dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = func_linear(A->mat[i][j]);
        }
    }
    return ans;
}

double func_relu(double n) {
    return n >= 0 ? n : 0;
}

matrix *activation_relu(matrix *A) {
    matrix *ans = alloc2(A->dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = func_relu(A->mat[i][j]);
        }
    }
    return ans;
}

double func_sigmoid(double n) {
    return 1 / (1 + expf(-n));
}

matrix *activation_sigmoid(matrix *A) {
    matrix *ans = alloc2(A->dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = func_sigmoid(A->mat[i][j]);
        }
    }
    return ans;
}

double func_tanh(double n) {
    return (expf(n) - expf(-n)) / (expf(n) + expf(-n));
}

matrix *activation_tanh(matrix *A) {
    matrix *ans = alloc2(A->dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = func_tanh(A->mat[i][j]);
        }
    }
    return ans;
}

double derivative_func_linear(double n) {
    return 1;
}

matrix *derivative_linear(matrix *A) {
    matrix *ans = alloc2(A->dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = derivative_func_linear(A->mat[i][j]);
        }
    }
    return ans;
}

double derivative_func_relu(double n) {
    if (n == 0) return NAN;
    else if (n > 0) return 1;
    else return 0;
}

matrix *derivative_relu(matrix *A) {
    matrix *ans = alloc2(A->dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = derivative_func_relu(A->mat[i][j]);
        }
    }
    return ans;
}

double derivative_func_sigmoid(double n) {
    return func_sigmoid(n) * (1 - func_sigmoid(n));
}

matrix *derivative_sigmoid(matrix *A) {
    matrix *ans = alloc2(A->dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = derivative_func_sigmoid(A->mat[i][j]);
        }
    }
    return ans;
}

double derivative_func_tanh(double n) {
    return 1 - pow(func_tanh(n), 2);
}

matrix *derivative_tanh(matrix *A) {
    matrix *ans = alloc2(A->dims);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = derivative_func_tanh(A->mat[i][j]);
        }
    }
    return ans;
}