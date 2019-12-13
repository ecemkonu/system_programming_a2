#include <linux/sched.h>
#include <linux/errno.h>

asmlinkage long sys_set_nice_int(pid_t pid, int value){
  struct task_struct *task;
  task = find_task_by_vpid(pid);
  if(task == NULL){
    return ESRCH; //return process not found
  }
  task->nice_inc = value;
  return 0;
}
