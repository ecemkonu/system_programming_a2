# System Programming Assignment 2

In this project, a nice increment variable is added to task_struct. Initial process, namely process 0 is modified to initialize this value to zero. By assigning this to zero, other functions initializing the kernel won't be affected. <br/>
Exit and fork calls are modified to change generated childrens nice value ( a scheduling variable in range of [-20, 19], 19 meaning least priority). Nice increment increments this nice value for each new generated children and when a parent exits, this value will be modified by using new parents nice value.

## How to Execute
This project is written for Lubuntu 14.04.1, newer versions or other distrubitions of linux may be incompatible.
<br/>
Move Linux source into directory you want to work with.
<br/>
Make directory for nice increment and modify the files added in this repo, copy pasting will be sufficient.
<br/>
Run the command
`make localmodconfig` in terminal generate configuration for kernel.
<br/>
To compile the kernel, run command `fakeroot
make-kpkg --initrd --append-to-version=-custom kernel_image
kernel_headers`
Two output files will be generated, linux image and linux headers.
<br/>
The install the compiled kernel, first make sure that you are in generic version of linux. If another custom kernel is installed, to remove it, return back to generic kernel then run the following commands <br/> `sudo dpkg -r linux-image-3.13...custom` <br/>
`sudo dpkg -r linux-headers-3.13...custom` <br/>

Alternatively, to install a new custom kernel following commands must be run: <br/>
`sudo dpkg -i linux-image-3.13...` , which is the deb file for linux-image created in parent directory by compilation <br/>
`sudo dpkg -i linux-headers-3.13...` <br/>

After installing, do not forget to modify grub file to make custom kernel versions available at run time. Run
`sudo nano /etc/default/grub` and comment out `GRUB_HIDDEN_TIMEOUT = 0`
<br/>
Update grub by running `sudo update-grub` <br/>

After restarting, new kernel will be shown as custom in boot time, execute it and nice_inc system calls will be implemented. You can run the test function for running the new system call implemented.
