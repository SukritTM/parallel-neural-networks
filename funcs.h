#include "matrix.h"

// functions:
double func_linear(double n);
matrix *activation_linear(matrix *A);

double func_relu(double n);
matrix *activation_relu(matrix *A);

double func_sigmoid(double n);
matrix *activation_sigmoid(matrix *A);

double func_tanh(double n);
matrix *activation_tanh(matrix *A);

// derivatives:
double derivative_func_linear(double n);
matrix *derivative_linear(matrix *A);

double derivative_func_relu(double n);
matrix *derivative_relu(matrix *A);

double derivative_func_sigmoid(double n);
matrix *derivative_sigmoid(matrix *A);

double derivative_func_tanh(double n);
matrix *derivative_tanh(matrix *A);