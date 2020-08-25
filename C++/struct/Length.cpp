#include <cstdlib>
#include <iostream>

class cLength
{
    private:
        double mili;
    public:
        void SetMili(double m) {mili = m;}
        double GetMili() {return mili;}
        void OutMili() {printf("length = %fmil\n", GetMili());}
        void SetInch(double i) {mili = i *25.4;}
        double GetInch() { return mili/25.4;}
        void OutInch() {printf("Length = %finch\n", GetInch());}
};

int main() {
    cLength m;

    m.SetInch(3);
    m.OutMili();
}