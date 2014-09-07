#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/fs_struct.h>
#include <linux/path.h>
#include <linux/dcache.h>
#define SUCCESS 0;

MODULE_AUTHOR("Soorej P <Soorej_Ponnandi@dell.com>");
MODULE_DESCRIPTION("Module to track operations on a file");
MODULE_LICENSE("GPL v2");


/* Module to track a file from kernel 
 *
 */
int __init ft_init(void)
{
	struct super_block *sb;
	struct inode *s_inode;
	printk(KERN_INFO "File Tracker started %d -> %s\n",current->pid,current->fs->root.dentry->d_name.name);
	sb = current->fs->root.dentry->d_sb;
	s_inode = ilookup(sb,3680126);
	printk(KERN_INFO "inode info %ld\n",s_inode->i_mtime.tv_sec);
	return SUCCESS;
}

void __exit ft_exit(void)
{
	printk(KERN_INFO "File Tracker exited %d -> %s\n",current->pid,current->comm);
}

module_init(ft_init);
module_exit(ft_exit);
