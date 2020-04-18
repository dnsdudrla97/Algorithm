#include <stdio.h>
#include <string.h>

int main(void)
{
    char st[128];
    puts("\"STRING\"의 처음 3개의 문자를 비교한다.");
    puts("\"XXXX\"를 입력하면 종료한다.");
    while (1) {
        printf("문자열 st : ");
        scanf("%s", st);
        if (strncmp("XXXX", st, 3) == 0)
            break;
        printf("strncmp(\"STRING\", st, 3) = %d\n", strncmp("STRING", st, 3));
    }

    return 0;
}