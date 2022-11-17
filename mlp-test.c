#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "mlp.h"

int main() {
    double xtrnar[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    matrix *X_train = matrix2((int[]){4, 2}, xtrnar);

    double ytrnar[4][1] = {
        {0},
        {1},
        {1},
        {1}
    };
    matrix *Y_train = matrix2((int[]){4, 1}, ytrnar);

    double xtstar[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    matrix *X_test = matrix2((int[]){4, 2}, xtstar);

    double ytstar[4][1] = {
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

    // model *or = make_model(2, 3);
    // printf("model with %d layers and an input size of %d\n", or->num_layers, or->input_dim);
    // model_train(or, 10, 4, X_train, Y_train);
    // matrix *y = model_predict(or, 4, X_test);
    // model_evaluate(or, 4, X_test, Y_test);

    unalloc(X_train);
    unalloc(Y_train);
    unalloc(X_test);
    unalloc(Y_test);
    // free(or);
    return 0;
}