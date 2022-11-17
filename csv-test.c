#include <stdio.h>
#include "matrix.h"

int main() {
    matrix *csv_data = read_csv("datasets/iris/iris_test_label.csv");
    printm(csv_data);
}