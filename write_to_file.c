#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open a file for writing
    int fd = open("message.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Text to write to the file
    char text[] = "CSE 29\nCSE 30\n";

    // Write the text to the file
    ssize_t bytes_written = write(fd, text, sizeof(text) - 1); // Exclude the null terminator
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    printf("%ld bytes is written to the file message.txt successfully!\n", bytes_written);

    return 0;
}

