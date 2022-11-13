#include <stdlib.h>
#include "matrix.h"

typedef struct layer {
    matrix *weights;
    matrix *biases;
    matrix *num_inputs;
} layer;

typedef struct model {
    int num_layers;
    int num_inputs;
    layer *layers;
} model;

void add_layer(
    model *model,
    int num_nodes
);

model *make_model(
    int num_inputs,
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