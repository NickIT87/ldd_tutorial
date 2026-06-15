#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <asm/current.h>

static void current_exit(void)
{
	printk("current pid : %d , current process : %s\n",current->pid, current->comm);
}

static  int current_init(void)
{
	printk("current pid : %d , current process : %s\n",current->pid, current->comm);
	return 0;
}

module_init(current_init);
module_exit(current_exit);

MODULE_LICENSE("GPL");
