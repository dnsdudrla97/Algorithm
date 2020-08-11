#include <stdio.h>
char* s1();
char* s2();
char** hello(char* h);

int* input();

int main(void)
{
    char* hi = "hello, World";
    char** hi_ptr=hello(hi);
    printf("%s \n", *hi_ptr);

    int* p = input();
    char* schar1 = s1();
    char* schar2 = s2();
    printf("%d \n", *p);
    printf("%s \n", schar1);
    printf("%s \n", schar2);

    return (0);
}

int* input()
{
    static int num1;
    scanf("%d", &num1);
    return &num1;
}

char* s1()
{
    static char* namin = "NAMIN";
    return namin;
}

char* s2()
{
    static char go[] = "gogoNAMIN";
    return go;
}

char** hello(char* h)
{
    static char* name;
    name=h;
    return &name;
}