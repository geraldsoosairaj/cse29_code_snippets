#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[64]; // A buffer on the stack
    strcpy(buffer, input); // This does not check the size of input
    printf("Buffer contents: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    vulnerable_function(argv[1]);
    return 0;
}

// Sample run: ./stack_smash $(python3 -c 'print("A" * 72 + "\xef\xbe\xad\xde")')
// -fno-stack-protector
