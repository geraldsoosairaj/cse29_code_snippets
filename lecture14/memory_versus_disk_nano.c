#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 1000000  // Adjust the size of data to write

long long timespec_diff_ns(struct timespec *start, struct timespec *end) {
    return (end->tv_sec - start->tv_sec) * 1000000000LL + (end->tv_nsec - start->tv_nsec);
}

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
    struct timespec start_memory, end_memory;
    clock_gettime(CLOCK_MONOTONIC, &start_memory);
    // Simulate writing to memory by performing some operations
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] *= 2;
    }
    clock_gettime(CLOCK_MONOTONIC, &end_memory);

    // Measure time taken to write to disk
    struct timespec start_disk, end_disk;
    clock_gettime(CLOCK_MONOTONIC, &start_disk);
    // Simulate writing to disk by opening a file and writing data to it
    FILE* file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    for (int i = 0; i < DATA_SIZE; i++) {
        fprintf(file, "%d\n", data[i]);
        fsync();
    }
    fclose(file);
    clock_gettime(CLOCK_MONOTONIC, &end_disk);

    // Calculate time differences
    long long time_memory = timespec_diff_ns(&start_memory, &end_memory);
    long long time_disk = timespec_diff_ns(&start_disk, &end_disk);

    printf("Time taken to write to memory: %lld nanoseconds\n", time_memory);
    printf("Time taken to write to disk: %lld nanoseconds\n", time_disk);

    // Free allocated memory
    free(data);

    return 0;
}

