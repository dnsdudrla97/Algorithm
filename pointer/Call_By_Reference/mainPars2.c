#include <stdio.h>

int main(int argc, char** argv)
{
    int i = 0;
    if (argc > 4) {
        printf("문자열의 수가 너무 많다. \n");
        printf("프로그램을 종료한다.\n");
        return 1;
    }

    printf("0번째 문자열 : %s \n", *(argv+0));
    printf("1번째 문자열 : %s \n", *(argv+1));
    printf("2번째 문자열 : %s \n", *(argv+2));
    printf("3번째 문자열 : %s \n", *(argv+3)); 
    
    return 0;
}