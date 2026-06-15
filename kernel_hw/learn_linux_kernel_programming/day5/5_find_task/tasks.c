#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

#include <linux/sched.h>
#include <linux/sched/signal.h>

static unsigned int PID = 1;
module_param(PID, uint, 0400);

void print_task(struct task_struct *task)
{
	printk("process : %s, parent process : %s\n", task->comm, task->parent->comm);

}

static int init_find_task(void)
{
	
	struct task_struct  *task = NULL;

	for_each_process(task) {
		if (task->pid == (pid_t)PID) {
			print_task(task);
		}
	}

	return 0;
}

static void exit_find_task(void)
{
    printk("GOOD BYE:find_task!!\n");
}

module_init(init_find_task);
module_exit(exit_find_task);

MODULE_LICENSE("GPL");
