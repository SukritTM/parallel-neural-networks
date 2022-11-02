#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "funcs.h"
#include "perceptron.h"

perceptron * perceptron_init(
    matrix *(*activation_function)(matrix *),
    int learning_rate,
    int input_size
) {
    perceptron *model = (perceptron *)malloc(sizeof(perceptron));
    model->learning_rate = learning_rate;
    model->activation_function = activation_function;
    model->weights = randrange2(
        (int[]){input_size, 1},
        (int[]){-1, 1}
    );
    return model;
}

void perceptron_train(perceptron * model, matrix *X, matrix *Y, int num_iter) {

}

matrix *predict_predict(perceptron *model, matrix *X);

matrix *predict_evaluate(perceptron *model, matrix *X, matrix *Y);