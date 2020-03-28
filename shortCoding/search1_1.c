#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
    int i = 0;
    a[n] = key; // sentinel

    while(1)
    {
        if (a[i] == key) break;
        i++;
    }
    return i == n ? -1 : i;
}

int main()
{
  int i, nx, ky, idx;
  int* x;

  puts("선형 검색");
  printf("요소 개수 : ");
  
  scanf("%d", &nx);
  x = calloc(nx + 1, sizeof(int));  // 요소의 개수가 (nx + 1)인 int형 배열 선언
  
  for(i = 0; i < nx; i++) { // 값을 읽어 들인 것은 nx개
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  printf("검색값 : ");
  scanf("%d", &ky);

  idx = search(x, nx, ky);  // 배열에서 x에서 값이 ky인 요소를 선형 검색

  if(idx == -1)
    puts("검색에 실패");
  else
    printf("%d(은)는 x[%d]에 있다.\n", ky, idx);

  free(x);  // 배열해제

  return 0;
  
}