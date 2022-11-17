#include <stdio.h>
#include "matrix.h"
#include "funcs.h"
#include "perceptron.h"

int main() {
    perceptron *p = perceptron_init(activation_sigmoid, derivative_sigmoid, 0.5, 3);
    printm(p->weights);
    matrix *inp = random2((int[]){0, 1});
    printm(inp);
    double prediction = perceptron_predict(p, inp);
    printf("%f\n\n", prediction);

    matrix *X[4] = {
        matrix2((int []){1, 2}, (double [][2]){{0, 0}}),
        matrix2((int []){1, 2}, (double [][2]){{0, 1}}),
        matrix2((int []){1, 2}, (double [][2]){{1, 0}}),
        matrix2((int []){1, 2}, (double [][2]){{1, 1}})
    };

    double Y[4] = {0, 1, 1, 1};

    perceptron_train(p, X, Y, 4, 10); printf("\n");

    printf("%f\n", perceptron_predict(p, random2((int[]){0, 0})));
    printf("%f\n", perceptron_predict(p, random2((int[]){0, 1})));
    printf("%f\n", perceptron_predict(p, random2((int[]){1, 0})));
    printf("%f\n", perceptron_predict(p, random2((int[]){1, 1})));


    // double (*test_func)(double) = func_relu;
    // printf("%f\n", test_func(5));
    // printf("%f\n", test_func(-5));
    // printm(matrix2((int []){1, 2}, (double [][2]){{1, 1}}));
}