#include <linux/module.h>
#include <linux/kernel.h>

static int __init mod_init(void)
{
	/* Set by default based on the module file name. */
	pr_info("name = %s\n", THIS_MODULE->name);
	pr_info("version = %s\n", THIS_MODULE->version);
	/* ERROR: nope, not part of struct module. */
	/*pr_info("name = %s\n", THIS_MODULE->name);*/
	return 0;
}

static void __exit mod_exit(void) {}

module_init(mod_init)
module_exit(mod_exit)
MODULE_INFO(name, "Embedded");
MODULE_INFO(OS, "Linux");
MODULE_VERSION("1.0");
MODULE_LICENSE("GPL");
