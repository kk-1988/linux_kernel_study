#include <linux/module.h>

#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/stat.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/tty.h>
#include <linux/kmod.h>
#include <linux/gfp.h>

static int major = 0;

static ssize_t hello_drv_read(struct file *file, char __user *buf, size_t size, loff_t *offset)
{
	printk("hello_drv_read...\r\n");
}

static ssize_t hello_drv_write(struct file *file, char __user *buf, size_t size, loff_t *offset)
{
	printk("hello_drv_write...\r\n");
}

static int hello_drv_open(struct inode *node, struct file *file)
{
	printk("hello_drv_open...\r\n");
}

static int hello_drv_close(sturct inode *node, struct file *file)
{
	printk("hello_drv_close...\r\n");
}

static struct file_operations hello_drv = {
	.owner = THIS_MODULE,
	.open = hello_drv_open,
	.read = hello_drv_read,
	.write = hello_drv_write,
	.release = hello_drv_close,
};

//
