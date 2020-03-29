#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[20];
    int age;
    char address[100];
};

struct Person* gerPerson()
{
    struct Person* p  = malloc(sizeof(struct Person));

    strcpy(p->name, "나민");
    p->age = 24;
    strcpy(p->address, "서울");

    return (p);    
};

int main()
{
    struct Person* p1;
    p1 = gerPerson();

    printf("이름: %s\n", p1->name);
    printf("주소: %s\n", p1->address);
    printf("나이: %d\n", p1->age);

    free(p1);
    return (0);

    
}
