#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "julina.h"

/*
 * Format:
 * 3 2 : 1 2 3 4 5 6
 * Yields:
 * [[1 2]
 *  [3 4]
 *  [5 6]]
 */
Matrix *read_matrix(char *s) {
    int rows, cols, size;
    rows = strtol(s, &s, 10);
    cols = strtol(s, &s, 10);
    size = rows * cols;
    double aa[size];
    s += 3; // space colon space
    int i;
    for (i = 0; i < size; i++) {
        aa[i] = strtol(s, &s, 10);
    }
    return new_matrix(aa, rows, cols);
}

int main(int argc, char **argv) {
    srand(time(NULL));

    Matrix *a = read_matrix("6 1 : 1 0 0 0 0 1");
    print_matrix(a);
    free_matrix(a);
}
