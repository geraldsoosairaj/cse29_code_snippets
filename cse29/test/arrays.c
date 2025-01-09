#include <stdlib.h>

int* copy_array(int *a, int len) {
    int *parray = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        parray[i] = a[i];
    }
    return parray;
}

int main() {
    int arr[3] = {10, 20, 30};
    int *arr_copy = copy_array(arr, 3);
    // assume we finish using arr_copy
    free(arr_copy);
    return 0;
}
