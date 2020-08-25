// class
#include<stdio.h>

class Master {
    private:
        int x = 10;

    public:
        void botMaker(unsigned int& mm) {
            for (x; x < 100; x++)
                mm += x;
        }

};

int main() {
    Master m;
    unsigned int mm = 10;
    printf("test : %d\n", mm);
    m.botMaker(mm);
    printf("test2 : %d\n", mm);

    return 0;
    
}