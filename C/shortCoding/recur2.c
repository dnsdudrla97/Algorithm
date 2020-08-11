#include <stdio.h>
void hanoi(int n, int x, int y) {

    if (n > 1) {
        hanoi(n - 1, x, 6 - x - y);
    }
    printf("원반:[%d] %d기둥에서 %d기둥으로\n",n, x, y);

    if (n > 1) {
        hanoi(n - 1, 6 - x - y, y);
    }

}

int main(void) {
    hanoi(3, 1, 3);
    return (0);
}