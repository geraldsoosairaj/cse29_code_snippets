#include <stdio.h>

int main() {
    int letter = '3';
    // ASCII value for the letter '0' is 48
    printf("%c  %d  %x\n", letter, letter, letter);
    
    int hex = 0x41;
    printf("%x %d %c\n", hex, hex, hex);

    char ch = 'a'; 
    printf("%c\n", ch + 1);
    return 0;
}

