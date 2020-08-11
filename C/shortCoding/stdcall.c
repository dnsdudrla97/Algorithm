#include <stdio.h>
#include <stdbool.h>
typedef struct
{
    int Parent;     /*Parent Record*/
    char *Name;     /*행정명*/
} tag_City;

tag_City arCity[] = {
    -1,
    "대한민국",
    0,
    "서울특별시",
    1,
    "동대문구",
    2,
    "청량리동",
    2,
    "회기동",
    2,
    "신설동",
    1,
    "한강구",
    6,
    "퐁당동",
    6,
    "월척동",
    0,
    "경기도",
    9,
    "화성시",
    9,
    "금성시",
    9,
    "목성시",
};

bool HaveChild(int idx)
{
    int i;
    for (i = 0; i < sizeof(arCity) / sizeof(arCity[0]); i++)
    {

        if (arCity[i].Parent == idx)
        {
            return true;
        }
    }
    return false;
}
void PrintCity(int Parent, int indent)
{
    int i, j;
    for (i = 0; i < sizeof(arCity) / sizeof(arCity[0]); i++)
    {

        if (arCity[i].Parent == Parent)
        {

            for (j = 0; j < indent; j++)
                putchar(' ');

            printf("%s\n", arCity[i].Name);

            if (HaveChild(i))
            {
                PrintCity(i, indent + 2);
            }
        }
    }
}

void main()
{
    PrintCity(-1, 0);
}