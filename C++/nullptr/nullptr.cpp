#include <iostream>
using namespace std;

int const_x(const char* p, char x)
// p[]에 존재하는 x와 동일한 값의 수를 센다.
// p는 0으로 끝나는 char의 배열을 가리킨다고 가정
// (그렇지 않으면 아무것도 가리키지 않는다.)
{
    if (p == nullptr)
        return 0;
    int count = 0;
    for (; *p!=0; ++p)
        if (*p == x)
            ++count;
    return count;
}

int const_y(const char* p, char x){
// p[]에 존재하는 x와 동일한 값의 수를 센다.
// p는 0으로 끝나는 char 배열을 가리킨다고 가정(그렇지 않으면 아무것도 가리키지 않는다.)
    if (p == nullptr)
        return 0;
    int count = 0;
    while (*p) {
        if (*p == x) {
            ++count;
            cout<<*p<<'\n';
        }
        ++p;
    }
    return count;
}


int main(void) {
    printf("r: %d\n", const_y("AHCDEHGHIJKLNM", 'H'));

    return 0;
    
}