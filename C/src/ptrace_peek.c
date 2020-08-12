#include <sys/ptrace.h>

struct user_regs_struct {
        long ebx, ecx, edx, esi, edi, ebp, eax;
        unsigned short ds, __ds, es, __es;
        unsigned short fs, __fs, gs, __gs;
        long orig_eax, eip;
        unsigned short cs, __cs;
        long eflags, esp;
        unsigned short ss, __ss;
};

int main(int argc, char *argv[])
{

        struct user_regs_struct regs;
        int ret, pid, i;

        pid = atoi(argv[1]);
        ret = ptrace(PTRACE_ATTACH, pid, 0, 0);
        printf("return : %d\n", ret);

        ptrace(PTRACE_GETREGS, pid, 0, 0);
        printf("stack = %p\n", regs.esp);

        unsigned int data;
        for(i=0; i<200; i++)
        {
                data = ptrace(PTRACE_PEEKDATA, pid, regs.esp+i*4, 0);
                printf("%08x\n", data);
        }
        ptrace(PTRACE_DETACH, pid, 0, 0);
}
