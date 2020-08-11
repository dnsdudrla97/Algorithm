#include <stdio.h>

int factorial(int n) {
    if (n == 1 || n == 0) {
        return (n);
    }

    return (factorial(n - 1) * n);

}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n",factorial(n));

    return (0);
}