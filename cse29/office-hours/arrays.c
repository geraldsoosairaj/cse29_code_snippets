#include <stdio.h>

int main() {
    int arr[5];
    printf("%d %d\n", *(arr+1), arr[1]);
    int *parr = arr;
    parr = parr + 1;
    arr[2] = 100;
    printf("%d %d\n", arr[2], *(parr + 1));
    *(parr + 0) = 200;
    return 0;
}

