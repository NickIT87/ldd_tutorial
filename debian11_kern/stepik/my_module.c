#include <linux/module.h>


int init_module(void)
{
	printk(KERN_INFO "Hello, loading\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Leaving\n");
}

MODULE_LICENSE("GPL");
