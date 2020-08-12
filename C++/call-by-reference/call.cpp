#include <iostream>
using namespace std;

void increment(int& c) {c+=1;}
int main(){
    int test;
    cout<<"HI:"<<"\n";
    cin>>test;

    cout<<"OH:"<<test<<"\n";

    increment(test);
    cout<<"HO:"<<test<<"\n";


    return 0;
}