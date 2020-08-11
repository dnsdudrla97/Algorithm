#include <stdio.h>
#include <string.h>
void DoSelect(const char* szSQL)
{
    // query start
}


void main(void)
{
    char szSQL[128];

    strcpy(szSQL, "select * from tblGirl where height > 165");
    DoSelect(szSQL);
    strcat(szSQL, " and weight < 55");
    DoSelect(szSQL);
}
volatile