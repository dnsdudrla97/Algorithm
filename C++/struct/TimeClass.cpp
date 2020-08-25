#include <cstdlib>
#include <iostream>

class cTime
{
    private:
        int hour, min, sec;
    public:
        void SetTime(int h, int m, int s) {
            hour = h;
            min = m;
            sec = m;
        }
        void OutTime() {
            std::cout<<"Current Time is "<<hour<<":"<<min<<":"<<sec<<"\n";
        }
};

int main() {
    cTime Now;
    Now.SetTime(10, 30, 40);
    Now.OutTime();
    return 0;
}