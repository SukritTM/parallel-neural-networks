#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

typedef struct model {
    int num_layers;
    matrix *weights;
    matrix *biases;
    int input_dim;
} model;

model *make_model(int input_dim, int num_layers) {
    model *ans = (model *)malloc(sizeof(model));
    ans->input_dim = input_dim;
    ans->num_layers = num_layers;
    return ans;
}

void model_train(model *model, int n, matrix *x, matrix *y) {
    model->weights = randrange2((int[]){model->input_dim, model->num_layers}, (int []) {-1, 1});
    model->biases = randrange2((int[]){1, model->num_layers}, (int []) {-1, 1});
    printm(model->weights);
    printm(model->biases);

    
}

matrix * model_predict(model *model, int n, matrix *x) {}

void model_evaluate(model *model, int n, matrix *x, matrix *y) {}

int main() {
    float xtrnar[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    matrix *X_train = matrix2((int[]){4, 2}, xtrnar);

    float ytrnar[4][1] = {
        {0},
        {1},
        {1},
        {1}
    };
    matrix *Y_train = matrix2((int[]){4, 1}, ytrnar);

    float xtstar[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    matrix *X_test = matrix2((int[]){4, 2}, xtstar);

    float ytstar[4][1] = {
        {0},
        {1},
        {1},
        {1}
    };
    matrix *Y_test = matrix2((int[]){4, 1}, ytstar);

    printm(X_train);
    printm(Y_train);
    // printm(X_test);
    // printm(Y_test);

    model *or = make_model(2, 3);
    printf("model with %d layers and an input size of %d\n", or->num_layers, or->input_dim);
    model_train(or, 4, X_train, Y_train);
    // matrix *y = model_predict(or, 4, X_test);
    // model_evaluate(or, 4, X_test, Y_test);

    unalloc(X_train);
    unalloc(Y_train);
    unalloc(X_test);
    unalloc(Y_test);
    free(or);
    return 0;
}