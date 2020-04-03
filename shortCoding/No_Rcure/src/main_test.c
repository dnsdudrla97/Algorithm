#include <stdio.h>
#include "Instack.h"
#include "nrecur.h"

int main(void) {
    int n;
    printf("numberic : ");
    scanf("%d", &n);
    nrecur(n);
    return (0);
}