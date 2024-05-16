#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float averageMat_v1(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [i][j]
            total += mat[i][j];
        }
    }

    return (float) total / (n * n);
}

float averageMat_v2(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [j][i]
            total += mat[j][i];
        }
    }

    return (float) total / (n * n);
}

int main() {
    int n = 3000; // matrix size
    int **mat;
    int i, j;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for the matrix
    mat = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    // Populate the matrix with some sample values
    int counter = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat[i][j] = counter++;
        }
    }

    // Calculate time taken to run averageMat_v1 function
    start = clock();
    float avg1 = averageMat_v1(mat, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Print the average and time taken
    printf("Average of the matrix: %.2f\n", avg1);
    printf("Time taken to calculate average: %f milli seconds\n", cpu_time_used * 1000);

    // Calculate time taken to run averageMat_v1 function
    start = clock();
    float avg2 = averageMat_v2(mat, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Print the average and time taken
    printf("Average of the matrix: %.2f\n", avg2);
    printf("Time taken to calculate average: %f milli seconds\n", cpu_time_used * 1000);


    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}

