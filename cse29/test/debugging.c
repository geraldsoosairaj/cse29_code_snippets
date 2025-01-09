#include <stdio.h>

void set_value(int *ptr) {
    *ptr = 10;
}

int main() {
    int *ptr = NULL;
    set_value(ptr);
    printf("The value at ptr is: %d\n", *ptr);
    return 0;
}

