/*저장한 문자열을 출력한다.*/
#include <stdio.h>

int main(void)
{
    char st[10];
    st[0] = 'A';
    st[1] = 'B';
    st[2] = 'C';
    st[3] = 'D';
    st[4] = '\0';
    printf("%s\n",st);
    st[5] = 'X';
    printf("%s\n",st);

    printf("%d",sizeof(char*));
    return 0;
}