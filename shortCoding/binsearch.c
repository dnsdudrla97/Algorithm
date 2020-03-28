#include <stdio.h>
#include <stdlib.h>

/*
 bsearch*() 함수 구현 / 이진 검색 수행
*/
/*key: key, base: search array, nmemb: array of element, size: array data size,
comp: compare function address
*/
void *bsearchx(const void* key, const void* base,
                size_t nmemb, size_t size, int(*comp)(const void*, const void*))
{
    size_t pr = nmemb - 1;
    size_t pl = 0;
    size_t pc;
    char* x = (char *)base;

    if (nmemb > 0)
    {
        while(1)
        {
            int compare = comp((const void*)&x[(pc = (pr + pl) / 2) * size], key);

            /*first number*/
            if (compare == 0)
            {
                while (pc > pl)
                {
                    if (comp((const void*)&x[(pc - 1) * size], key)) break;
                    pc--;
                }
                return &x[pc * size];
            }
            else if (pl == pr) break;
            else if (compare < 0) pl = pc + 1;
            else pr = pc - 1;
        }
    }
    return NULL;
}

/* compare function */
int cmp(const int* x, const int* y)
{
    if (*x < *y)
		return -1;
	else if (*x > *y)
		return 1;
	else
		return 0;

}

int main(void)
{
	int i, nx, ky;
	int *x;		/* 배열의 첫 번째 요소에 대한 포인터 */
	int *p;		/* 검색된 요소에 대한 포인터 */

	puts("bsearchx 함수를 사용하여 검색");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	/* 요소수 nx인 int형 배열을 생성 */

	printf("오름차순으로 입력하세요.\n");
	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);	/* 하나 앞의 값보다 작으면 다시 입력 */
	}

	printf("검색 값 : ");
	scanf("%d", &ky);

	p = bsearchx(&ky,								/* 검색 값에 대한 포인터 */
		x,											/* 배열 */
		nx,											/* 요솟수 */
		sizeof(int),								/* 요소의 크기 */
		(int(*)(const void *, const void *))cmp	/* 비교 함수 */
	);

	if (p == NULL)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, (int)(p - x));

	free(x);	

	return 0;
}