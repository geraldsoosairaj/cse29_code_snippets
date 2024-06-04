#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Start\n");
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child Process\n");
    } else if (pid > 0) {
        // Parent process
        printf("Parent Process\n");
    } else {
        // Fork failed
        printf("Fork failed\n");
    }

    printf("End\n");
    return 0;
}

