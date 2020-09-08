#include <iostream>

int& function(int& ref) {
    int ref = 2;
    return ref;
}

int main() {
    int c = 3;
    int b = function(c);

    int arr[3] = {1,2,3};
    int(&ref)[3] = arr;

    ref[0] = 2;
    ref[1] = 3;
    
}