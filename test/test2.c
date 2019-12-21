#include <sys/resource.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NR_nicecall 356

int main(void){
    int nice_inc = 5;
    int y;
    pid_t pid = getpid();
    int status =0;
    y = syscall(NR_nicecall, pid, nice_inc);
    if(fork() == 0)
    {
      if(fork() ==0)
      {
        printf("\n%d is the nice value of the grandchild\n", getpriority(PRIO_PROCESS, getpid()));
      }
      else{
        pid_t wpid;
        while ((wpid=waitpid(-1,&status,0))!=-1) ; //if wait is commented out, nice value will be set to 0,
      printf("\n%d is the nice value of the child\n", getpriority(PRIO_PROCESS, getpid()));
      exit(0);
    }
 }
    else{
      pid_t wpid;
      while ((wpid=waitpid(-1,&status,0))!=-1) ;
      printf("\n%d is the nice value of the parent\n", getpriority(PRIO_PROCESS, getpid()));
    }
    return 0;
}
