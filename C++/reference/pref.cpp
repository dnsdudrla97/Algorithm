#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void InputName(char *&Name)
{
    Name = (char *)malloc(12);
    strcpy(Name, "Cabin");
}

int main()
{
    char *Name;
    InputName(Name);
    printf("이름은 %s입니다\n", Name);
    free(Name);
}