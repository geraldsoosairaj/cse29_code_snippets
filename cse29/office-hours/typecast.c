#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pa = malloc(4 * sizeof(int));
    pa[0] = 0xA1B2C3D4;
    pa[1] = -1;
    pa[2] = 0;
    pa[3] = 100;
    printf("pa = %p, *pa = %x\n", pa, *pa);
    char *pc = (char *)pa;
    printf("%x %x\n", pa[0], pc[1]);
    double *pd = (double *)pa;

    int *ptr = NULL;
    printf("%d\n", *ptr);

    return 0;
}

