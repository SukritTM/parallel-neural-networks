#include <stdlib.h>
#include "matrix.h"

typedef struct model {
    int num_layers;
    matrix *weights;
    matrix *biases;
    int input_dim;
} model;

model *make_model(
    int input_dim,
    int num_layers
);

void model_train(
    model *model,
    int epochs,
    int n,
    matrix *x,
    matrix *y
);

matrix *model_predict(
    model *model,
    int n,
    matrix *x
);

void model_evaluate(
    model *model,
    int n,
    matrix *x,
    matrix *y
);