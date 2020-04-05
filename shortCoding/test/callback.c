#include <stdio.h>
#include <stdlib.h>

void (*registered_callback)(int ntimes);

void setCallback(void (*callback)(int ntimes))
{
    registered_callback = callback;
}

void callCallback()
{
    (*registered_callback)(10);
}

void printHelloWorldNTimes(int ntimes)
{
    for (int i = 1; i <= ntimes; i++)
    {
        printf("<%2d>This is a HelloWorld print function callback!!\n", i);
    }
    return;
}

int main(void)
{
    puts("Callback Function Demo");

    setCallback(printHelloWorldNTimes);
    callCallback();
    return EXIT_SUCCESS;
}