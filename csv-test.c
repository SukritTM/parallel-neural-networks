#include <stdio.h>
#include "matrix.h"

int main() {
    matrix *csv_data = read_csv("datasets/iris/test_data.csv");
    printm(csv_data);

    int len = csv_data->dims[0];
    matrix **x = m2ma(csv_data);
    for (int i = 0; i < len; i++)
        printm(x[i]);

    matrix *csv_labels = read_csv("datasets/iris/test_labels.csv");
    printm(csv_data);

    int len2 = csv_labels->dims[0];
    double *y = cm2da(csv_labels);
    for (int i = 0; i < len2; i++)
        printf("%f ", y[i]);
}

/*
matrix *ans[row];
for (int i = 0; i < row; i++) {
    double *mat[1] ={vals[i]};
    ans[i] = matrix2(
        (int[2]){1, column},
        mat
    );
}
return ans;
*/