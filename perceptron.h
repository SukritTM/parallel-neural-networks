#include "matrix.h"
#include "funcs.h"

typedef struct perceptron {
    matrix *weights;
    double bias;
    matrix *(*activation_function)(matrix *);
    matrix *(*derivative_func)(matrix *);
    int learning_rate;
    int input_size;
} perceptron;

perceptron *perceptron_init(
    matrix *(*activation_function)(matrix *),
    matrix *(*derivative_func)(matrix *),
    int learning_rate,
    int input_dims
);

void perceptron_train(perceptron * model, matrix *X[], double Y[], int sample_size, int num_iter);

double perceptron_predict(perceptron *model, matrix *X);

void perceptron_unalloc(perceptron *model);

double predict_evaluate(perceptron *model, matrix *X[], double Y[], int sample_size);