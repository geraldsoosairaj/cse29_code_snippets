#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("Begin.\n");
    pid_t ret = fork();    
    if (ret == 0) {
        printf("I am the child. My pid is %d\n", getpid());
    } else if (ret > 0) {
        wait(NULL);
        printf("I am the parent. My pid is %d and my child's pid is %d\n", getpid(), ret);
    } else {
        printf("fork failed!");
        exit(1);
    }
    printf("End.\n");
    return 0;
}

