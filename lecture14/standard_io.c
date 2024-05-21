#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *src_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Open the source file for reading
    src_file = fopen("source.txt", "r");
    if (src_file == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open the destination file for writing
    dest_file = fopen("destination.txt", "w");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(src_file);
        return 1;
    }

    // Copy contents from source file to destination file
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src_file)) > 0) {
        printf("bytes read = %ld\n", bytes_read);
        size_t bytes_written = fwrite(buffer, sizeof(char), bytes_read, dest_file);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            fclose(src_file);
            fclose(dest_file);
            return 1;
        }
    }

    if (ferror(src_file)) {
        perror("Error reading from source file");
        fclose(src_file);
        fclose(dest_file);
        return 1;
    }

    // Close both files
    if (fclose(src_file) == EOF) {
        perror("Error closing source file");
        return 1;
    }
    if (fclose(dest_file) == EOF) {
        perror("Error closing destination file");
        return 1;
    }

    printf("Text contents successfully copied from source file to destination file.\n");

    return 0;
}

