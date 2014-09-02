#include <linux/module.h>
#define SUCCESS 0;

MODULE_AUTHOR("Soorej P <Soorej_Ponnandi@dell.com>");
MODULE_DESCRIPTION("Module to track operations on a file");
MODULE_LICENSE("GPL v2");


/* Module to track a file from kernel 
 *
 */

int __init ft_init(void)
{
	printk(KERN_INFO "File Tracker started");

	return SUCCESS;
}

void __exit ft_exit(void)
{
	printk(KERN_INFO "File Tracker exited");
}

module_init(ft_init);
module_exit(ft_exit);
