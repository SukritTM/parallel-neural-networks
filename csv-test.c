#include <stdio.h>
#include "matrix.h"

int main() {
    matrix *csv_data = read_csv("datasets/iris/train_labels.csv");
    printm(csv_data);
}