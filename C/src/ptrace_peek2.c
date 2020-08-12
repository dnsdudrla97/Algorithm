#include <sys/ptrace.h>
#include <sys/user.h>

int main(int argc, char *argv[])
{

        struct user_regs_struct regs;
        int ret, pid, i, j;
        pid = atoi(argv[1]);

        ret = ptrace(PTRACE_ATTACH, pid, 0, 0);
        printf("return : %d\n", ret);

        ptrace(PTRACE_GETREGS, pid, 0,0);
        printf("stack = %p\n", regs.rsp);

        unsigned int data;
        unsigned char data2[9];
        for(i=0; i<600; i++)
        {
                data = ptrace(PTRACE_PEEKDATA, pid, regs.rsp+i*8, 0);
                memcpy(&data2, &data, 8);
                for(j=0; j<8; j++){
                        if(isprint(data2[j]))
                                printf("%c ", data2[j]);
                        else
                                printf(". ");
                }
        }

        ptrace(PTRACE_DETACH, pid, 0, 0);
}
