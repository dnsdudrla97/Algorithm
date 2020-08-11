#include <stdio.h>
#include "IntSet.h"

int main(void)
{
	IntSet s1, s2, s3;
	Init(&s1, 24);
	Init(&s2, 24);
	Init(&s3, 24);

	Add(&s1, 10);			/* s1 = {10} */
	Add(&s1, 15);			/* s1 = {10, 15} */
	Add(&s1, 20);			/* s1 = {10, 15, 20} */
	Add(&s1, 25);			/* s1 = {10, 15, 20, 25} */

	Assign(&s2, &s1);		/* s2 = {10, 15, 20, 25} */
	Add(&s2, 12);			/* s2 = {10, 15, 20, 25, 12} */
	Remove(&s2, 20);		/* s2 = {10, 15, 12, 25} */
	Assign(&s3, &s2);		/* s3 = {10, 15, 12, 25} */

	printf("s1 = "); PrintLn(&s1);
	printf("s2 = "); PrintLn(&s2);
	printf("s3 = "); PrintLn(&s3);

	printf("집합 s1에 15가 들어있%s.\n", IsMember(&s1, 15) > 0 ? "습니다" : "지 않습니다");
	printf("집합 s2에 25가 들어있%s.\n", IsMember(&s2, 25) > 0 ? "습니다" : "지 않습니다");
	printf("집합 s1과 s2는 서로 같%s.\n", Equal(&s1, &s2) ? "습니다" : "지 않습니다.");
	printf("집합 s2와 s3는 서로 같%s.\n", Equal(&s2, &s3) ? "습니다" : "지 않습니다.");

	Terminate(&s1);
	Terminate(&s2);
	Terminate(&s3);

	return 0;
}