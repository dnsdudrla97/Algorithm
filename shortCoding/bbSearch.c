#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
  char name[10];
  int height;
  int weight;
} Person;

// person 형의 비교 함수(오름차순으로 이름 정렬)
int npcmp(const Person *x, const Person *y){
  return strcmp(x->name, y->name);
}

int main() {
  Person x[] = {					/* 배열 요소는 이름의 오름차순으로 */
		{ "김영준", 179, 79 }, 		/* 정렬되어 있지 않으면 안 됩니다. */
		{ "나민", 172, 63 },
		{ "이수진", 176, 52 },
		{ "최윤미", 165, 51 },
		{ "함진아", 181, 73 },
		{ "홍연의", 172, 84 },
	};
  
  int nx = sizeof(x) / sizeof(x[0]);  // 배열의 요소 개수
  int retry;
  
  puts("이름으로 검색합니다.");
  // do {
    Person temp, *p;
    // printf("이름 : ");
    // scanf("%s", temp.name);
    strcpy(temp.name, "나민");
    p = bsearch(
        &temp,
         x, 
         nx, 
         sizeof(Person), 
         (int(*)(const void *, const void *)) npcmp
    );

    if (p == NULL)
      puts("검색에 실패했습니다.");
    else {
      puts("검색 성공!! 아래 요소를 찾았습니다.");
      printf("x[%d] : %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);
    }
    // printf("다시 검색할까요(1) 예 / (0) 아니오 : ");
    // scanf("%d", &retry);
  // } while(retry == 1);

  return 0;

}