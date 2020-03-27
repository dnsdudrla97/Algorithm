/* int형 집합 IntSet의 사용 예(2) */
#include <stdio.h>
#include "IntSet.h"

enum { ADD, RMV, SCH };

/*--- 데이터 입력 ---*/
int scan_data(int sw)
{
	int data;
	
	switch (sw) {
	case ADD: printf("추가할 데이터 : "); break;
	case RMV: printf("삭제할 데이터 : "); break;
	case SCH: printf("검색할 데이터 : "); break;
	}

	scanf("%d", &data);

	return data;
}

int main(void)
{
	IntSet s1, s2, temp;
	
	Initialize(&s1, 512); 
	Initialize(&s2, 512); 
	Initialize(&temp, 512);

	while (1) {
		int m, x, idx;

		printf("s1 = "); PrintLn(&s1);
		printf("s2 = "); PrintLn(&s2);
		printf("(1) s1에 추가 (2) s1에서 삭제 (3) s1에서 검색 (4) s1←s2 (5) 여러 연산\n",
			"(6) s2에 추가 (7) s2에서 삭제 (8) s2에서 검색 (9) s2←s1 (0) 종료 : ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1: x = scan_data(ADD); Add(&s1, x); break;			/* 추가 */
		case 2: x = scan_data(RMV); Remove(&s1, x); break;		/* 삭제 */
		case 3: x = scan_data(SCH); idx = IsMember(&s1, x);		/* 검색 */
			printf("s1에 들어있%s.\n", idx >= 0 ? "습니다" : "지 않습니다"); break;
		case 4: Assign(&s1, &s2); break;						/* s2를 s1에 대입 */
		case 5: printf("s1 == s2 = %s\n", Equal(&s1, &s2) ? "true" : "false");
			printf("s1 & s2 = "); Intersection(&temp, &s1, &s2);
			PrintLn(&temp);
			printf("s1 | s2 = "); Union(&temp, &s1, &s2);
			PrintLn(&temp);
			printf("s1 - s2 = "); Difference(&temp, &s1, &s2);
			PrintLn(&temp);
			break;
		case 6: x = scan_data(ADD); Add(&s2, x); break;			/* 추가 */
		case 7: x = scan_data(RMV); Remove(&s2, x); break;		/* 삭제 */
		case 8: x = scan_data(SCH); idx = IsMember(&s2, x);		/* 검색 */
			printf("s2에 들어있%s.\n", idx >= 0 ? "습니다" : "지 않습니다"); break;
		case 9: Assign(&s2, &s1); break;						/* s1을 s2에 대입 */
		}
	}

	Terminate(&s1); 
	Terminate(&s2); 
	Terminate(&temp);
	
	return 0;
}