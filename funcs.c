#include <stdio.h>
#include <math.h>
#include "matrix.h"

float func_linear(float n) {
    return n;
}

matrix *activation_linear(matrix *A) {
    matrix *ans = alloc2(A->dims);
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = func_linear(A->mat[i][j]);
        }
    }
    return ans;
}

float func_relu(float n) {
    return n >= 0 ? n : 0;
}

matrix *activation_relu(matrix *A) {
    matrix *ans = alloc2(A->dims);
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = func_relu(A->mat[i][j]);
        }
    }
    return ans;
}

float func_sigmoid(float n) {
    return 1 / (1 + expf(-n));
}

matrix *activation_sigmoid(matrix *A) {
    matrix *ans = alloc2(A->dims);
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = func_sigmoid(A->mat[i][j]);
        }
    }
    return ans;
}

float func_tanh(float n) {
    return (expf(n) - expf(-n)) / (expf(n) + expf(-n));
}

matrix *activation_tanh(matrix *A) {
    matrix *ans = alloc2(A->dims);
    for (int i = 0; i < A->dims[0]; i++) {
        for (int j = 0; j < A->dims[1]; j++) {
            ans->mat[i][j] = func_tanh(A->mat[i][j]);
        }
    }
    return ans;
}

float derivative_func_linear(float n) {}

matrix *derivative_linear(matrix *A) {}

float derivative_func_relu(float n) {}

matrix *derivative_relu(matrix *A) {}

float derivative_func_sigmoid(float n) {}

matrix *derivative_sigmoid(matrix *A) {}

float derivative_func_tanh(float n) {}

matrix *derivative_tanh(matrix *A) {}