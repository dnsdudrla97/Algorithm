#include <iostream>

struct tag_Position {
    int x;
    int y;
    char ch; // Member varibale = Field
    void printPosition() { // Member Function = Method
       std::cout<<"x : "<<x<<" y: "<<y<<" ch : "<<ch<<"\n";
    }
};



int main() {
    tag_Position tp;
    tp.x = 10;
    tp.y = 20;
    tp.ch = 'A';
    tp.printPosition();
}