#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "mlp.h"

model *make_model(int num_inputs, int num_layers) {
    model *ans = (model *)malloc(sizeof(model));
    ans->num_inputs = num_inputs;
    ans->num_layers = num_layers;
    ans->layers = (layer *)calloc(num_layers, sizeof(layer));
    return ans;
}
