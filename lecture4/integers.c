#include <stdio.h>
#include <limits.h>

int main() 
{
    int max_signed_int = INT_MAX;
    int min_signed_int = INT_MIN;
    int max_unsigned_int = UINT_MAX;
    printf("max_signed_int = %d\n", max_signed_int);
    printf("min_signed_int = %d\n", min_signed_int);
    printf("max_unsigned_int = %u\n", max_unsigned_int);
    return 0;
}

