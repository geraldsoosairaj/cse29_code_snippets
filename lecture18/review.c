#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int var = 42;
    int *ptr = &var;
    
    printf("Parent process (PID: %d):\n", getpid());
    printf("Address of var: %p\n", ptr);
    printf("Value of var: %d\n\n", *ptr);
    
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {  // Child process
        printf("Child process (PID: %d):\n", getpid());
        printf("Address of var: %p\n", ptr);
        printf("Value of var: %d\n\n", *ptr);
        
        // Modify the variable in the child process
        *ptr = 100;
        printf("Child process (PID: %d) after modification:\n", getpid());
        printf("Address of var: %p\n", ptr);
        printf("Value of var: %d\n\n", *ptr);
  } else {  // Parent process
        wait(NULL);  // Wait for the child process to finish
        
        printf("Parent process (PID: %d) after child modification:\n", getpid());
        printf("Address of var: %p\n", ptr);
        printf("Value of var: %d\n\n", *ptr);
    }
    
    return 0;
}

