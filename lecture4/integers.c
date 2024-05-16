#include <stdio.h>
#include <limits.h>

int main() 
{
    int max_signed_int = INT_MAX;
    int min_signed_int = INT_MIN;
    unsigned int max_unsigned_int = UINT_MAX;
    long max_signed_long_int = LONG_MAX;
    long min_signed_long_int = LONG_MIN;
    unsigned long max_unsigned_long_int = ULONG_MAX;

    printf("max_signed_int = %d\n", max_signed_int);
    printf("min_signed_int = %d\n", min_signed_int);
    printf("max_unsigned_int = %u\n", max_unsigned_int);
    printf("----------------------------------------------------\n");
    printf("max_signed_long_int = %ld\n", max_signed_long_int);
    printf("min_signed_long_int = %ld\n", min_signed_long_int);
    printf("max_unsigned_long_int = %lu\n", max_unsigned_long_int);
    return 0;
}

