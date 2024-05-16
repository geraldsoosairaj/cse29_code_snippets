#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *p1 = malloc(sizeof(char));
    short *p2 = malloc(sizeof(short));
    int *p3 = malloc(sizeof(int));
    int *p4 = malloc(4 * sizeof(int));
    int *p5 = malloc(1);

    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    printf("p3 = %p\n", p3);
    printf("p4 = %p\n", p4);
    printf("p5 = %p\n", p5);

    return 0;
}

