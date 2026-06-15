#include <linux/module.h> /* for MODULE_*. module_* */
#include <linux/printk.h> /* for pr_* */
#include <linux/cpumask.h> /* for num_online_cpus */

static int __init mod_init(void)
{
	pr_info("number of online cpus is %d\n", num_online_cpus());
	return 0;
}


static void __exit mod_exit(void)
{
}

module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("GPL");



