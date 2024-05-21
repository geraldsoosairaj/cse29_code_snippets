#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    // Open the source file for reading
    int src_fd = open("source.txt", O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Open the destination file for writing
    int dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(src_fd);
        return 1;
    }

    // Buffer for reading data
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read data from source file and write it to destination file
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        // printf("bytes read = %ld\n", bytes_read);
        ssize_t bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytes_read == -1) {
        perror("Error reading from source file");
        close(src_fd);
        close(dest_fd);
        return 1;
    }

    // Close both files
    if (close(src_fd) == -1) {
        perror("Error closing source file");
        return 1;
    }
    if (close(dest_fd) == -1) {
        perror("Error closing destination file");
        return 1;
    }

    printf("Text contents successfully copied from source file to destination file.\n");

    return 0;
}

