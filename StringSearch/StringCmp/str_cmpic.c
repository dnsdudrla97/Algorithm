#include <stdio.h>
#include <ctype.h>

/*얼파벳 대문자 / 소문자를 구분하지 않고 두 문자열을 비교하는 함수*/
/*
    A : 65
            --> +32
    a : 97
    대문자 A ~ Z : 65 ~ 90
    소문자 a ~ z : 97 ~ 122
*/
int str_cmpic(const char *s1, const char *s2)
{
    while (1)
    {
        if ((*s1 != *s2))
        {
            if (((int)*s1 >= 65) || ((int)*s1 <= 90))
            {
                if (((int)*s2 >= 97) || ((int)*s2 <= 122))
                {
                    if (((int)*s1 - 32) == ((int)*s2))
                    {
                        // printf("%d\n%d\n", ((int)*s1 - 32) , ((int)*s2));
                        s1++;
                        s2++;
                    }
                    else return (unsigned char)*s1 - (unsigned char)*s2;
                }
            }
            else if (((int)*s1 >= 97) || ((int)*s1 <= 122))
            {
                if (((int)*s2 >= 65) || ((int)*s2 <= 90))
                {
                    if (((int)*s1) == ((int)*s2 - 32))
                    {
                        s1++;
                        s2++;
                    }
                    else return (unsigned char)*s1 - (unsigned char)*s2;
                }
            }
        } else {
          s1++;
          s2++;
        }        
        if (*s1 == '\0') break;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int main(void)
{
    char apple[16] = "GHIF";
    char tmp[16] = "ghef";
    
    printf("comfirm %s %s \n",apple, tmp);
    printf("result = %d \n", str_cmpic(apple, tmp));
    
    return 0;
}