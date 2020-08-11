#include <stdio.h>
#include "Member.h"
#include "LinkedList.h"

/*Menu*/
typedef enum
{
    TERMINATE,
    INS_FRONT,
    INS_REAR,
    RMV_FRONT,
    RMV_REAR,
    PRINT_CRNT,
    RMV_CRNT,
    SRCH_NO,
    SRCH_NAME,
    PRINT_ALL,
    CLEAR,
    PURGE,
    RETRIEVE,
} Menu;

/*Menu select*/
Menu SelectMenu(void)
{
    int i, ch;
    char *mstring[] = {
        "머리에 노드를 삽입",
        "꼬리에 노드를 삽입",
        "머리 노드를 삭제",
        "꼬리 노드를 삭제",
        "선택한 노드를 출력",
        "선택한 노드를 삭제",
        "번호로 검색",
        "이름으로 검색",
        "모든 노드를 출력",
        "모든 노드를 삭제",
        "Purge",
        "Retrieve",
    };
    do
    {
        for (i = TERMINATE; i < RETRIEVE; i++) 
        {
            printf("(%2d) %-40s ", i + 1, mstring[i]);
            if ((i % 3) == 2)
                putchar('\n');
        }
        printf("(0) 종료 : ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > RETRIEVE);
    return (Menu)ch;
}

/*Main*/
int main(void)
{
    Menu menu;
    List list;
    Init(&list); /*연결 리스트 초기화*/

    do
    {
        Member x;
        int research;

        switch (menu = SelectMenu())
        {
        /*머리에 노드를 삽입*/
        case INS_FRONT:
            x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
            InsertFront(&list, &x);
            break;

        /*꼬리에 노드를 삽입*/
        case INS_REAR:
            x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
            InsertRear(&list, &x);
            break;

        /*머리 노드를 삭제*/
        case RMV_FRONT:
            RemoveFront(&list);
            break;

        /*꼬리 노드를 삽입*/
        case RMV_REAR:
            RemoveRear(&list);
            break;

        /*선택한 노드의 데이터 출력*/
        case PRINT_CRNT:
            PrintLnCurrent(&list);
            break;

        /*선택한 노드 삭제*/
        case RMV_CRNT:
            RemoveCurrent(&list);
            break;

        /*번호로 검색*/
        case SRCH_NO:
            x = ScanMember("검색", MEMBER_NO);
            if (search(&list, &x, MemberNoCmp) != NULL)
                PrintLnCurrent(&list);
            else
                puts("그 번호의 데이터가 없다.");
            break;

        /*이름으로 검색*/
        case SRCH_NAME:
            x = ScanMember("검색", MEMBER_NAME);
            if (search(&list, &x, MemberNoCmp) != NULL)
                PrintLnCurrent(&list);
            else
                puts("그 이름의 데이터가 없다.");

            break;

        /*모든 노드의 데이터를 출력*/
        case PRINT_ALL:
            Print(&list);
            break;

        /*모든 노드를 삭제*/
        case CLEAR:
            Clear(&list);
            break;
        
        /*Purge*/
        case PURGE:
            Purge(&list,MemberNoCmp);
            break;
        /*Retrieve*/
        case RETRIEVE:
            printf("[몇번째 노드의 데이터 값 : ");
            scanf("%d", &research);
            if (Retrieve(&list, research) != NULL)
                PrintLnCurrent(&list);
        default:
            break;
        }
    } while (menu != TERMINATE);
    Terminate(&list); /*연결리스트 종료*/

    return 0;
}