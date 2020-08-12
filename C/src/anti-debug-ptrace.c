#include <sys/ptrace.h>

void main(void) {
	char buf[20] = "namin";
	if (ptrace(PTRACE_TRACEME, 0) < 0)
	{
		printf("NOT DEBUGGING!!!\n");
		exit(1);
	}
	while(1) {
		printf("%s\n", buf);
		sleep(1);
	}

}

