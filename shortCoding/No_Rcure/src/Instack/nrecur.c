#include <stdio.h>
#include "Instack.h"
#include "nrecur.h"


void nrecur(int n) {

    int sw = 0;
    struct Instack ssdn, nndn;
    Init(&ssdn, 100);
    Init(&nndn, 100);
    while(1) {
        if (n > 0) {
            Push(&ssdn,sw);
            Push(&nndn,n);

            if (sw == 0) {
                n = n - 1;
            } else if (sw == 1) {
                n = n - 2;
                sw = 0;
            }
            continue;
        }
    
        do {
            Pop(&nndn,&n);
            Pop(&ssdn,&sw);
            sw++;
            if (sw == 2) {
                printf("%d ", n);
                if (Isempty(&nndn)) {
                    return;
                }
            }

        } while (sw == 2);
    }
    Terminator(&nndn);
    Terminator(&ssdn);

}