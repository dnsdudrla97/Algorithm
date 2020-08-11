#include "LibFactorial.h"

unsigned long long factorial(const int nth)
{
    if (nth <= 0)
    {
        return (0);
    }

    unsigned int result = 1;

    for (int i = 1; i<=nth; i++)
    {
        result = result * i;
    }
    return result;
}