#include <stdio.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0);

void selection(int a[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(int, a[i], a[min]);
    }
}
