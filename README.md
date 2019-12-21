# System Programming Assignment 2

In this project, a nice increment variable is added to task_struct. By adding necessary changes, 
Exit and fork calls are modified to change generated childrens nice value ( a scheduling variable in range of [-20, 19], 19 meaning least priority). Nice increment increments this nice value for each new generated children and when a parent exits, this value will be modified by using new parents nice value.
