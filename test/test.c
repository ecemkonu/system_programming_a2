#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#define NR_nicecall 356

int main(void){
    int nice_inc = 8;
    int y;
    pid_t pid = getpid();
    y = syscall(NR_nicecall, pid, nice_inc);
    if(fork() == 0)
    {
      printf("\n%d is the nice value of the child\n", getpriority(PRIO_PROCESS, getpid()));
    }
    else{
      printf("\n%d is the nice value of the parent\n", getpriority(PRIO_PROCESS, getpid()));
    }
    return 0;
}
