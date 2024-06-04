#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Start\n");
    pid_t pid = fork();

    if (pid == 0) {
        pid_t ret = fork();
        if (ret == 0) {
            printf("Child Process 2\n");
        } else if (ret > 0) {
            wait(NULL);
            printf("Child Process 1\n");
        } else {
            printf("Fork failed\n");
        }
    } else if (pid > 0) {
        // Parent process
        printf("Start: Parent Process\n");
        wait(NULL);
        printf("End: Parent Process\n");
    } else {
        // Fork failed
        printf("Fork failed\n");
    }

    printf("End\n");
    return 0;
}

