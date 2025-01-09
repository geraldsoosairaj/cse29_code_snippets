#include <stdio.h>
#include <string.h>

void mystery(char *s, int len) {
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            printf("%c", s[i] - 'A' + 'a');
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}


int main() {
    char str[10] = "ABC456cbA";
    mystery(str, strlen(str));
    return 0;
}

