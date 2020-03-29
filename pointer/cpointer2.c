#include <stdio.h>
int main(void)
{
    char array1[]={'A', 'B', 'C', 'D', '\0'};
    char array2[]={'A', 'B', 'C', 'D'};

    char* array="NAMIN";

    printf("%s\n", array);
    printf("%s\n", array+1);
    printf("%s\n", array+2);
    printf("%s\n", array+3);
    printf("================\n");

    printf("%s\n", array1);
    printf("%s\n", array2);

    return (0);
}