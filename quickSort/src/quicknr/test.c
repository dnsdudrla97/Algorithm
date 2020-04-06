
void print(const int x[], int lf, int rt){
    int i;
    printf("a[%d] ~ a[%d] : {", lf, rt);
        for (i = lf; i < rt; i++)
            printf("%d ", x[i]);
        printf("%d}\n", x[rt]);
}