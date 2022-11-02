#include "matrix.h"
#include "funcs.h"

typedef struct perceptron {
    matrix *weights;
    matrix *biases;
    matrix *(*activation_function)(matrix *);
    int learning_rate;
    int input_size;
} perceptron;

perceptron *perceptron_init(
    matrix *(*activation_function)(matrix *),
    int learning_rate,
    int input_dims
);

void perceptron_train(perceptron * model, matrix *X, matrix *Y, int num_iter);

matrix *perceptron_predict(perceptron *model, matrix *X);

matrix *perceptron_evaluate(perceptron *model, matrix *X, matrix *Y);

void perceptron_unalloc(perceptron *model);