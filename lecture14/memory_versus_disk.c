#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 1000000  // Adjust the size of data to write

int main() {
    // Allocate memory for data
    int* data = (int*)malloc(DATA_SIZE * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Generate some random data
    srand(time(NULL));
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = rand();
    }

    // Measure time taken to write to memory
    clock_t start_memory = clock();
    // Simulate writing to memory by performing some operations
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] *= 2;
    }
    clock_t end_memory = clock();

    // Measure time taken to write to disk
    clock_t start_disk = clock();
    // Simulate writing to disk by opening a file and writing data to it
    FILE* file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    for (int i = 0; i < DATA_SIZE; i++) {
        fprintf(file, "%d\n", data[i]);
    }
    fclose(file);
    clock_t end_disk = clock();

    // Calculate time differences
    double time_memory = ((double)(end_memory - start_memory)) / CLOCKS_PER_SEC;
    double time_disk = ((double)(end_disk - start_disk)) / CLOCKS_PER_SEC;

    printf("Time taken to write to memory: %f seconds\n", time_memory);
    printf("Time taken to write to disk: %f seconds\n", time_disk);

    // Free allocated memory
    free(data);

    return 0;
}

