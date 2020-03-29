#include <stdio.h>

int main(void)
{

    char* p = &"ABCD";
    printf("%x \n",p);
    printf("%x \n",p+1);
    printf("%x \n",p+2);
    printf("%x \n",p+3);
    printf("%x \n",p+4);
    printf("-------------\n");

    printf("%x %x \n", &"ABCD", p);

    char* array[2]={"Good Moring", "C-lanaguae"};
    printf("%s \n", array[1]+2);    // lanaguage
    printf("%s \n", array[0]+5);    // Moring

    return (0);
    
}