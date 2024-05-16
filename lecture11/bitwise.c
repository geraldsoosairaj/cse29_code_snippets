#include <stdio.h>

int main() {
    unsigned int n = 0x1A2B3CD4;
    // least sig byte is 0x4D
    unsigned int least_sig_byte = n & 0xFF;
    printf("least_sig_byte = %x\n", least_sig_byte);

    // most sig byte is 0x1A
    unsigned int most_sig_byte = (n & 0xFF000000) >> 24;
    printf("most_sig_byte = %x\n", most_sig_byte);

    unsigned char *pc = (unsigned char *)&n;
    printf("%x\n", pc[0]);
    if (pc[0] == 0xD4) {
        printf("Machine is little endian!\n");
    } else if(pc[0] == 0x1A) {
        printf("Machine is big endian!\n");
    } else {
        printf("Unknown machine type!\n");
    }

    return 0;
}

