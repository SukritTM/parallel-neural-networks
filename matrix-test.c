#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    matrix *m1 = random2((int[]){3, 3});
    double nm2[3][3] = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 5, 1}
    };
    matrix *m2 = matrix2((int[]){3, 3}, nm2);
    // matrix *i3 = identity(3);

    // printm(m1);
    // printm(m2);
    // printm(i3);

    // matrix *m3 = matmul(m1, m2);
    // matrix *m4 = matmul(m3, i3);

    // printm(m3);
    // printm(m4);

    // matrix *m4T = transpose(m4);
    // printm(m4T);

    // unalloc(m1);
    // unalloc(m2);
    // unalloc(i3);
    // unalloc(m3);
    // unalloc(m4);
    // unalloc(m4T);

    matrix *ans = mul((double)2, m2);
    printm(m2);
    printm(ans);

    return 0;
}