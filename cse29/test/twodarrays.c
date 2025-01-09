#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matrix = malloc(sizeof(int) * 3);
    for(int i = 0; i < 3; i++) {
        matrix[i] = malloc((i + 1) * sizeof(int));
    }
    // assume the matrix is used here.

    // TODO: Write code to free the matrix!
    for(int i = 0; i < 3; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

