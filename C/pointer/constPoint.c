#include <stdio.h>
int main(void)
{
    char a='A';
    char b='B';
    char c='C';

    /* 포인터 변수에 다른 메모리 공간이 주소를 저장 못하게 한다. */
    char* const p=&a;

    *p='C';
    printf("%c \n",*p);
    printf("%c \n", a);

    // p=&b; -> error
    
    /* 포인터 변수를 통해 메모리 공간의 값을 변경하지 못하게 한다.*/
    const char* ptr=&b;

    // *ptr='D'; - error
    
    ptr=&a;
    printf("%c \n",*ptr);
    printf("%c \n", a);

    /* 포인터 변수를 통해 메모리 공간의 조소와 값 모두 변경하지 못하게 한다.*/
    const char* const ptrN=&c;

    printf("%c\n", c);
    printf("%c\n", *ptrN);

    // *ptrN = 'E'; -error
    // ptrN = &a; -error

    return (0);
    
}