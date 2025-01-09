#include <stdio.h>

void array_op1(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
}

void array_op2(int *arr, int rows, int cols) {
    for (int i = 0; i < (rows * cols); i++) {
        int *ptr = (arr + i);
        printf("%d ", *ptr);
    }
    printf("\n");
}

void array_op3(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int* ptr = *(arr + i);
            printf("%d ", *(ptr + j));
        }
        printf("\n");
    }
}

int main() {
    int arr[2][3] = {{10, 20, 30}, {40, 50, 60}};

    array_op1(arr, 2, 3);
    array_op2(&arr[0][0], 2, 3); // &arr[0][0] can also be (int*)arr
    array_op3((int **)arr, 2, 3); // &arr[0][0] can also be (int*)arr
    return 0;
}


