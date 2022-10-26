#include <stdio.h>
#include "matrix.h"
#include "funcs.h"

int main() {
    printf("matrices:\n");

    matrix *m1 = random2((int[]){3, 3});
    float nm2[3][3] = {
        {11, 2, -3},
        {3, -2, 1},
        {0, 5, -1}
    };
    matrix *m2 = matrix2((int[]){3, 3}, nm2);
    matrix *m3 = identity(3);

    printm(m1);
    printm(m2);
    printm(m3);

    printf("linear:\n");

    matrix *linear_m1 = activation_linear(m1);
    matrix *linear_m2 = activation_linear(m2);
    matrix *linear_m3 = activation_linear(m3);

    printm(linear_m1);
    printm(linear_m2);
    printm(linear_m3);

    unalloc(linear_m1);
    unalloc(linear_m2);
    unalloc(linear_m3);

    printf("relu:\n");

    matrix *relu_m1 = activation_relu(m1);
    matrix *relu_m2 = activation_relu(m2);
    matrix *relu_m3 = activation_relu(m3);

    printm(relu_m1);
    printm(relu_m2);
    printm(relu_m3);

    unalloc(relu_m1);
    unalloc(relu_m2);
    unalloc(relu_m3);

    printf("sigmoid:\n");

    matrix *sigmoid_m1 = activation_sigmoid(m1);
    matrix *sigmoid_m2 = activation_sigmoid(m2);
    matrix *sigmoid_m3 = activation_sigmoid(m3);

    printm(sigmoid_m1);
    printm(sigmoid_m2);
    printm(sigmoid_m3);

    unalloc(sigmoid_m1);
    unalloc(sigmoid_m2);
    unalloc(sigmoid_m3);

    printf("tanh:\n");

    matrix *tanh_m1 = activation_tanh(m1);
    matrix *tanh_m2 = activation_tanh(m2);
    matrix *tanh_m3 = activation_tanh(m3);

    printm(tanh_m1);
    printm(tanh_m2);
    printm(tanh_m3);

    unalloc(tanh_m1);
    unalloc(tanh_m2);
    unalloc(tanh_m3);

    printf("derivative_linear:\n");

    matrix *derivative_linear_m1 = derivative_linear(m1);
    matrix *derivative_linear_m2 = derivative_linear(m2);
    matrix *derivative_linear_m3 = derivative_linear(m3);

    printm(derivative_linear_m1);
    printm(derivative_linear_m2);
    printm(derivative_linear_m3);

    unalloc(derivative_linear_m1);
    unalloc(derivative_linear_m2);
    unalloc(derivative_linear_m3);

    printf("derivative_relu:\n");

    matrix *derivative_relu_m1 = derivative_relu(m1);
    matrix *derivative_relu_m2 = derivative_relu(m2);
    matrix *derivative_relu_m3 = derivative_relu(m3);

    printm(derivative_relu_m1);
    printm(derivative_relu_m2);
    printm(derivative_relu_m3);

    unalloc(derivative_relu_m1);
    unalloc(derivative_relu_m2);
    unalloc(derivative_relu_m3);

    printf("derivative_sigmoid:\n");

    matrix *derivative_sigmoid_m1 = derivative_sigmoid(m1);
    matrix *derivative_sigmoid_m2 = derivative_sigmoid(m2);
    matrix *derivative_sigmoid_m3 = derivative_sigmoid(m3);

    printm(derivative_sigmoid_m1);
    printm(derivative_sigmoid_m2);
    printm(derivative_sigmoid_m3);

    unalloc(derivative_sigmoid_m1);
    unalloc(derivative_sigmoid_m2);
    unalloc(derivative_sigmoid_m3);

    printf("derivative_tanh:\n");

    matrix *derivative_tanh_m1 = derivative_tanh(m1);
    matrix *derivative_tanh_m2 = derivative_tanh(m2);
    matrix *derivative_tanh_m3 = derivative_tanh(m3);

    printm(derivative_tanh_m1);
    printm(derivative_tanh_m2);
    printm(derivative_tanh_m3);

    unalloc(derivative_tanh_m1);
    unalloc(derivative_tanh_m2);
    unalloc(derivative_tanh_m3);

    unalloc(m1);
    unalloc(m2);
    unalloc(m3);

    return 0;
}