#include <stdio.h>

int main(void)
{
    int num1 = 3;
    char num2 = 'A';

    printf("add : %x, value : %d, value : %d \n", &num1, num1, *&num1);
    printf("add : %x, value : %d, value : %d \n", &num2, num2, *&num2);

    printf("%d %d \n", sizeof(int), sizeof(char));
    printf("%d %d \n", sizeof(num1), sizeof(num2));

    return (0);
}