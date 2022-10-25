#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "mlp.h"

model *make_model(int input_dim, int num_layers) {
    model *ans = (model *)malloc(sizeof(model));
    ans->input_dim = input_dim;
    ans->num_layers = num_layers;
    return ans;
}

void model_train(model *model, int epochs, int n, matrix *x, matrix *y) {
    model->weights = randrange2((int[]){model->input_dim, model->num_layers}, (int []) {-1, 1});
    model->biases = randrange2((int[]){n, model->num_layers}, (int []) {-1, 1});
    printf("weights:\n");
    printm(model->weights);
    printf("\nbiases:\n");
    printm(model->biases);

    matrix *out, *error;

    for (int i = 0; i < epochs; i++) {
        out = add(matmul(x, model->weights), model->biases);
        printm(out);
        error = add(y, mul(-1, out));
        printm(error);
        // model->weights = add(model->weights, error);
        // printm(model->weights);
    }
}

matrix * model_predict(model *model, int n, matrix *x) {}

void model_evaluate(model *model, int n, matrix *x, matrix *y) {}