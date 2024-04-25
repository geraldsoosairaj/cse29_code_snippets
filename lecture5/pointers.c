#include <stdio.h>

int main() {
    int n = 42;
    int *pn = &n; 

    printf("pn = %p\n", pn);
    printf("*pn = %d\n", *pn);



    printf("address of n = %p\n", &n);
    printf("sizeof n = %ld\n", sizeof(n));
    printf("sizeof pn = %ld\n", sizeof(pn));
    return 0;
}

