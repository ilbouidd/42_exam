unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4 | octet << 4));
}

#include <stdio.h>

int main()
{
    unsigned char octet = 254;
    unsigned char result = swap_bits(octet);
    printf("%d\n", result);
}
