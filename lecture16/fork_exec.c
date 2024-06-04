#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Start\n");
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
        // This line will not be executed if execvp is successful
        printf("Error in Child Process: execvp failed!\n");
    } else if (pid > 0) {
        // Parent process
        wait(NULL);  // Wait for child process to complete
        printf("Parent Process\n");
    } else {
        // Fork failed
        printf("Fork failed\n");
    }

    printf("End\n");
    return 0;
}

