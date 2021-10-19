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

/* 确定主设备号，为0表示让内核自动分配*/
static int major = 0;

/* 分配定义个file_operations 结构体 */
static struct file_operations hello_drv = {
	
};

/* 实现对应的open/read/write等函数,填入file_operations 结构体*/

/* */
