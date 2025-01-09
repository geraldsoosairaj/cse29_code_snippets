#include <stdio.h>

void string_copy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


int main() {
    char str[4] = "ABC";
    printf("str = %s\n", str);
    char new_str[4];
    string_copy()
    return 0;
}

