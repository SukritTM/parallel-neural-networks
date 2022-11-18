#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "matrix.h"
#include "funcs.h"
#include "perceptron.h"

int main(int argc, char **argv) {
    int num_threads = atoi(argv[1]);
    omp_set_num_threads(num_threads);
    // perceptron *p = perceptron_init(activation_sigmoid, derivative_sigmoid, 2, 2);
    // printm(p->weights);

    // matrix *X[4] = {
    //     matrix2((int []){1, 2}, (double [][2]){{0, 0}}),
    //     matrix2((int []){1, 2}, (double [][2]){{0, 1}}),
    //     matrix2((int []){1, 2}, (double [][2]){{1, 0}}),
    //     matrix2((int []){1, 2}, (double [][2]){{1, 1}})
    // };

    // double Y[4] = {0, 1, 1, 1};

    // perceptron_train(p, X, Y, 4, 100); printf("\n");

    // printf("%f\n", perceptron_predict(p, matrix2((int []){1, 2}, (double[][2]){0, 0})));
    // printf("%f\n", perceptron_predict(p, matrix2((int []){1, 2}, (double[][2]){0, 1})));
    // printf("%f\n", perceptron_predict(p, matrix2((int []){1, 2}, (double[][2]){1, 0})));
    // printf("%f\n", perceptron_predict(p, matrix2((int []){1, 2}, (double[][2]){1, 1})));
    // printf("Accuracy: %f\n", predict_evaluate(p, X, Y, 4));
    srand(1487824);
    // preprocessing
    matrix *X_train_mat = read_csv("datasets/iris/train_data.csv");
    matrix *y_train_mat = read_csv("datasets/iris/train_labels.csv");
    matrix *X_test_mat = read_csv("datasets/iris/test_data.csv");
    matrix *y_test_mat = read_csv("datasets/iris/test_labels.csv");

    int num_train = X_train_mat->dims[0];
    int num_test = X_test_mat->dims[0];

    matrix **X_train = m2ma(X_train_mat);
    matrix **X_test = m2ma(X_test_mat);
    double *y_train = cm2da(y_train_mat);
    double *y_test = cm2da(y_test_mat);

    double time = omp_get_wtime();
    perceptron *iris_model = perceptron_init(
        activation_sigmoid,
        derivative_sigmoid,
        0.5,
        4
    );
    perceptron_train(
        iris_model,
        X_train,
        y_train,
        num_train,
        800
    );
    double acc = predict_evaluate(iris_model, X_test, y_test, num_test);
    time = omp_get_wtime() - time;
    printf("took %f seconds | accuracy: %f\n", time, acc);
}