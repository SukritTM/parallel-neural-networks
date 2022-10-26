#include "matrix.h"

// functions:
float func_linear(float n);
matrix *activation_linear(matrix *A);

float func_relu(float n);
matrix *activation_relu(matrix *A);

float func_sigmoid(float n);
matrix *activation_sigmoid(matrix *A);

float func_tanh(float n);
matrix *activation_tanh(matrix *A);

// derivatives:
float derivative_func_linear(float n);
matrix *derivative_linear(matrix *A);

float derivative_func_relu(float n);
matrix *derivative_relu(matrix *A);

float derivative_func_sigmoid(float n);
matrix *derivative_sigmoid(matrix *A);

float derivative_func_tanh(float n);
matrix *derivative_tanh(matrix *A);