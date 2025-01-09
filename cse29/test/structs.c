
#include <stdio.h>
struct node {
    int data;
    struct node *next;
};


int main() {
    printf("%ld\n", sizeof(struct node));
    int n = 0xA1B2C3D4;
    int *pn = &n;
    char *pc = (char *)pn;
    printf("%x\n", pc[0] & 0xFF);
    return 0;
}

