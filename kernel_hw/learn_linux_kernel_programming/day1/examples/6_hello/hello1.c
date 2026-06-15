#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
static int test_hello1_init(void)
{
    printk(KERN_INFO"%s: In init\n", __func__);
    return 0;
}

static void test_hello1_exit(void)
{
    printk(KERN_INFO"%s: In exit\n", __func__);
}

module_init(test_hello1_init);
module_exit(test_hello1_exit);
