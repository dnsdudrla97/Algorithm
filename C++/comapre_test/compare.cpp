#include <iostream>
using namespace std;

bool accept()
{
    cout<<"Continue?(y or n)?\n";
    char answer = 0;
    cin>>answer;
    if (answer == 'y')
        return true;
    return false;
}

bool accept2()
{
    cout<<"Continue?(y or n)?\n";
    char answer=0;
    cin>>answer;
    switch (answer)
    {
    case 'y':
        return true;
    case 'n':
        return false;    
    default:
        cout<<"Access Denied!\n";
        return false;
    }
}

int main(void) {
    accept();
    return 0;
}