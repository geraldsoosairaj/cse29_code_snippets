#include <stdio.h>

int sum(int x, int y) {
    int result = x + y;
    return result;
}

int main() {
    int a = 1;
    int b = 2;
    int total = sum(a, b);
    printf("sum of %d and %d = %d\n", a, b, total);
    return 0;
}

