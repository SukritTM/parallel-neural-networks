#include <stdio.h>
#include "matrix.h"
#include "funcs.h"
#include "perceptron.h"

int main() {
    perceptron *p = perceptron_init(activation_relu, 0.5, 3);
}