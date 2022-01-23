#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x4e79ba4a, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x4b6dbab9, "cdev_del" },
	{ 0x2c7b3e8c, "cdev_add" },
	{ 0xcaf4ced0, "cdev_init" },
	{ 0x8eb16f11, "cdev_alloc" },
	{ 0x3fd78f3b, "register_chrdev_region" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x26d6bdfd, "module_refcount" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

