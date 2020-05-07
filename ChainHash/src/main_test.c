#include <stdio.h>
#include "MemberNew.h"
#include "ChainHash.h"

typedef enum
{
    TERMINATE,
    ADD,
    DELETE,
    SEARCH,
    CLEAR,
    DUMP
} Menu;

Menu SelectMenu(void)
{
    int ch;
    do
    {
        printf("(1)추가, (2)삭제, (3)검색, (4)모두 삭제, (5)덤프 (0)종료 : ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > DUMP);
    return (Menu)ch;
}

int main()
{
    Menu menu;
    ChainHash hash;
    Init(&hash, 13);
    do
    {
        int result;
        Member x;
        Node *temp;
        switch (menu = SelectMenu())
        {
        case ADD:
            x = ScanMember("추가", MEMBER_NO | MEMBER_NAME);
            result = Add(&hash, &x);
            if (result)
                printf("\a오류 : 추가에 실패하였다.(%s).\n",
                       (result == 1) ? "이미 등록됨" : "메모리 부족");
            break;

        case DELETE:
            x = ScanMember("삭제", MEMBER_NO);
            result = Remove(&hash, &x);
            if (result == 1)
                printf("\a오류 : 이 번호에 데이터가 존재하지 않다.\n");
            break;

        case SEARCH:
            x = ScanMember("검색", MEMBER_NO);
            temp = Search(&hash, &x);
            if (temp == NULL)
                printf("\a검색에 실패했다.\n");
            else
            {
                printf("검색에 성공했다. : ");
                PrintLnMember(&temp->data);
            }
            break;

        case CLEAR:
            Clear(&hash);
            break;

        case DUMP:
            Dump(&hash);
            break;
        default:
            break;
        }
    } while (menu != TERMINATE);
    Terminate(&hash);

    return 0;
}