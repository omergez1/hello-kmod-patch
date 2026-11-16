// SPDX-License-Identifier: GPL-2.0
/*
 * hello_kmod - a trivial kernel module.
 * Prints "hello world" when loaded and "bye bye world" when unloaded.
 */
#include <linux/module.h>

static int __init hello_kmod_init(void)
{
	pr_info("hello_kmod: hello world\n");
	return 0;
}

static void __exit hello_kmod_exit(void)
{
	pr_info("hello_kmod: bye bye world\n");
}

module_init(hello_kmod_init);
module_exit(hello_kmod_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Trivial hello world kernel module");
MODULE_AUTHOR("Omer Gez");
