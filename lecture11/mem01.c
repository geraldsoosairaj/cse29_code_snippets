#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p1 = malloc(1);
    char *p2 = malloc(1);
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    printf("p2 - p1 = %ld\n", p2 - p1);
    return 0;
}

