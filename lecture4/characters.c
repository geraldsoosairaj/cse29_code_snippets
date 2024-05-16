#include <stdio.h>

int main() {
    int character = '3';
    // ASCII value for the character '0' is 48
    printf("%c  %d  %x\n", character, character, character);

    int hex = 0x41;
    printf("%x %d %c\n", hex, hex, hex);

    char ch = 'b'; 
    printf("%c %c %c\n", (ch + 1), (ch - 1), ch);
    return 0;
}

