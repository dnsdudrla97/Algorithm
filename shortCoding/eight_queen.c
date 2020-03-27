
/*8-queen*/
#include <stdio.h>
// □ ■

int flag_a[8];  /* 각 행에 퀸을 배치했는지 체크하는 배열 행에 같은 같은 퀸이 있는지 체크*/
int flag_b[15]; /* 대각선 /에 퀸을 배치했는지 체크하는 배열*/
int flag_c[15]; /* 대각서 \에 퀸을 배치했는지 체크하는 배열 */
int pos[8];    /* 각 열에서 퀸의 위치 */
int count = 0;


/*--- 각 열에서 퀸의 위치 출력 ---*/
void print(void)
{
	int	 i, j;
    count++;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)
			printf("%s", j == pos[i] ? "■" : "□");
		putchar('\n');
	}
    printf("시도 횟수: %d", count);
	putchar('\n');
}


/* i열에서 알맞은 위치에 퀸을 배치 */
void set(int i)
{
    int j;
    for (j = 0; j < 8; j++) {
        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
        {
            pos[i] = j;
            if (i == 7)
                print();    /*모든 열에 배치를 마침*/
            else {
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
                set(i + 1);
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
            }
        }
    }
}
 
int main()
{
    int i;
    for (i = 0; i < 8; i++)
        flag_a[i] = 0;
    for (i = 0; i < 15; i++)
        flag_b[i] = flag_c[i] = 0;
    set(0);

    return (0);
}