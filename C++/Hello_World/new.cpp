#include <iostream>
#include <string.h>
// ptr = new type[(init)]; -> sizeof(type)

struct tag_Friend {
    char Name[10];
    int Age;
    double Height;
};

int* alloc_array(int n) {
    int *aa = new int[n];
    return aa;
}

int main() {
    int *ar = new int[5];
    int i;
    tag_Friend *pF = new tag_Friend;
    int* pi = new int(123);
    // *pi = 123;

    for (i=0; i < 5; i++) {
        ar[i] = i;
    }
    for (i=0; i < 5; i++) {
        std::cout<<"count : "<<ar[i]<<'\n';
    }
    std::cout<<"Input: ";
    std::cin>>i;
    alloc_array(i);


    strcpy(pF->Name, "Nmain");
    pF->Age = 24;
    pF->Height = 173;
    std::cout<<"name : \n"<<pF->Name<<"Age : \n"<<pF->Age<<"Height : \n"<<pF->Height<<"\n";
    
    std::cout<<"*pi = "<<*pi;

    delete pi, pF;
    delete [] ar;   // 동적할당한 배열을 꼭 [] 으로 해제하자 

    return 0;
}

