#include <stdio.h>
#include <stdbool.h>
typedef struct
{
    int id;
    int Parent;
    char *Name;
} tag_City;

tag_City arCity[] = {

    0,
    -1,
    "대한민국",

    1,
    0,
    "서울특별시",

    2,
    1,
    "동대문구",

    3,
    2,
    "청량리동",

    4,
    2,
    "회기동",

    5,
    2,
    "신설동",

    6,
    1,
    "한강구",

    7,
    6,
    "퐁당동",

    8,
    6,
    "월척동",

    9,
    0,
    "경기도",

    10,
    9,
    "화성시",

    11,
    9,
    "금성시",

    12,
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

            if (HaveChild(arCity[i].id))
            {

                PrintCity(arCity[i].id, indent + 2);
            }
        }
    }
}

void main()
 
{

    PrintCity(-1, 0);
}