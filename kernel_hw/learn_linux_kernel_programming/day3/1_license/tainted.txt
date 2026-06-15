At runtime, you can query the tainted state by reading 

$cat /proc/sys/kernel/tainted

If that returns 0, the kernel is not tainted;

any other number indicates the reasons why it is.

The easiest way to decode that number is the script kernel-chktaint

https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/tools/debugging/kernel-chktaint
