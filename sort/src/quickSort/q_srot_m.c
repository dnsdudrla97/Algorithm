#include <stdio.h>
#include <stdlib.h>

void memswap(void *x, void *y, int n)
{
    unsigned char *a = (unsigned char *)x;
    unsigned char *b = (unsigned char *)y;

    for (; n--; a++, b++)
    {
        unsigned char c = *a;
        *a = *b;
        *b = c;
    }
}

int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

void q_sort(void *base, size_t nemb, size_t size, int (*compare)(const void *, const void *))
{
    if (nemb > 0)
    {

        int pl = 0;
        int pr = nemb - 1;
        int pv = nemb;
        int pt = (pl + pr) / 2;
        char *v = (char *)base;
        char *x = NULL;

        do
        {
            if (pv != pt)
                x = &v[(pv = pt) * size];

            while (compare((const void *)&v[pl * size], x) < 0)
                pl++;
            while (compare((const void *)&v[pr * size], x) > 0)
                pr--;

            if (pl <= pr)
            {
                memswap(&v[pl * size], &v[pr * size], size);
                pl++;
                if (pr == 0)
                    goto err;
                pr--;
            }
        } while (pl <= pr);

        if (0 < pr)
            q_sort(&v[0], pr + 1, size, compare);
    err:
        if (pl < nemb - 1)
            q_sort(&v[pl * size], nemb - pl, size, compare);
    }
}

int main(void)
{
    int *x;
    int nx;
    int i;
    puts("numberic : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    q_sort(x, nx, sizeof(int), (int (*)(const void *, const void *))int_cmp);

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : %d\n", i, x[i]);
    }

    free(x);
    return (0);
}
