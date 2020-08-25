#include <iostream>
#include <cstdlib>
#include <unistd.h>

class Position
{
private:
    int x;
    int y;

public:
    void InitRandom()
    {
        std::srand(4112);

        x = std::rand();
        y = std::rand();
    }
    void OutPosition()
    {
        std::cout << x<< "\n";
        std::cout << y<< "\n";
    }
};

int main() {
    Position arPos[50];
    Position *pPos;
    int i;

    for (i = 0; i < sizeof(arPos)/sizeof(arPos[0]); i++) {
        arPos[i].InitRandom();
        arPos[i].OutPosition();
        // sleep(50);
    }

    // sleep(1000);
    pPos = arPos;
    for (i = 0; i < sizeof(arPos)/sizeof(arPos[0]); i++) {
        pPos->InitRandom();
        pPos->OutPosition();
        // sleep(40);
    }

}