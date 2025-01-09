#include <stdio.h>

int main() {
    int arr[2][3] = {{10, 20, 30}, {40, 50, 60}};
    int **arr_ptr = arr;

    printf("%d\n", arr_ptr[0][0]);
    return 0;
}

