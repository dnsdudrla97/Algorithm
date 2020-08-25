#include <iostream>
#include <stdio.h>

// private -> protected -> public
struct botMaster {
    private:
        int a;
        double b;
        char ch;
        void Initialize();
    public:
        int x;
        int y;
        void func(int i) {printf("%d", i);};
    protected:
        float k;
};

int main(){ 
    botMaster bM;
    bM.func(3);
    bM.x = 10;
    bM.y = 20;

    
}