#include <stdio.h>

void main()
{
    unsigned short us;

    us=65535;   /*2^16 - 1 -> unsigned short (65535) : max*/
    printf("us=%d\n", us);
    us++;       /*2^17 000000000000000000000*/
    printf("us=%d\n", us);
}