#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 42;
    int *pnum = &num;
    printf("pnum = %p\n", pnum);
    int *parr = malloc(sizeof(int) * 100);
    printf("parr = %p\n", parr);
    return 0;
}


