/* qsort 함수를 사용하여 구조체 배열 정렬 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[10];
    int height;
    int weight;

} Person;

/*--- Person형 비교 함수 (이름 오름차순 정렬) --- */
int npcmp(const Person *x, const Person *y)
{
    return strcmp(x->name, y->name);
}

/* Person 형 비교 함수(키 오름차순 정렬)*/
int hpcmp(const Person *x, const Person *y)
{
    return x->height < y->height ? -1 : x->height > y->height ? 1 : 0;
}

/* Person 형 비교 함수(몸무게 내림차순 정렬) */
int wpcmp(const Person *x, const Person *y)
{
    return x->weight < y->weight ? 1 : x->weight > y->weight ? -1 : 0;
}

/* 사람 no명의 데이터를 출력 */
void print_person(const Person x[], int no)
{
    int i;
    for (i = 0; i < no; i++)
        printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
}

int main(void)
{
    Person x[] = {
        {"sunmi", 170, 52},
        {"yoobin", 180, 70},
        {"sohee", 172, 63},
        {"namin", 173, 64}};

    int nx = sizeof(x) / sizeof(x[0]);

    puts("after sort");
    print_person(x, nx);

    /*name increase*/
    qsort(x, nx, sizeof(Person), (int (*)(const void *, const void *))npcmp);
    puts("\nbefore of name increase");
    print_person(x, nx);

    /*height increase*/
    qsort(x, nx, sizeof(Person), (int (*)(const void *, const void *))hpcmp);
    puts("\nbefore of height increase");
    print_person(x, nx);

    /*weight increase*/
    qsort(x, nx, sizeof(Person), (int (*)(const void *, const void *))wpcmp);
    puts("\nbefore of weight increase");
    print_person(x, nx);

    return (0);
}