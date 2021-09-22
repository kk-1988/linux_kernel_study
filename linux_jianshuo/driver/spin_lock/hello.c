#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/wait.h>
#include <linux/poll.h>
#include <linux/sched.h>
#include <linux/slab.h>

#define BUFFER_MAX  (10)
#define OK          (0)
#define ERROR       (-1)

struct cdev *gDev;
struct file_operations *gFile;
dev_t devNum;
unsigned int subDevNum = 1;
int reg_major = 232;
int reg_minor = 0;
char buffer[BUFFER_MAX];
spinlock_t count_lock;
int open_count = 0;

int hello_open(struct inode *p, struct file *f)
{
    //down(&sema);
    spin_lock(&count_lock);
    //临界段的代码必须要少，且不能调用会引起睡眠的函数
    if(open_count >= 1)
    {
        //up(&sema);
        spin_unlock(&count_lock);
        printk(KERN_INFO"device is busy\r\n");
        return -EBUSY;
    }
    open_count++;
    //up(&sema);
    spin_unlock(&count_lock);

    printk(KERN_EMERG"hello_open\r\n");
    return 0;
}

int hello_close(struct inode *inode, struct file *filp)
{
    if(open_count != 1)
    {
        printk(KERN_INFO"something wrong,hello close is failed\r\n");
        return -EFAULT;
    }

    open_count--;

    return 0;
}

ssize_t hello_write(struct file *f, const char __user *u,  size_t s, loff_t *l)
{
    printk(KERN_EMERG"hello_write\r\n");
    return 0;
}

ssize_t hello_read(struct file *f, char __user *u, size_t s, loff_t *l)
{
    printk(KERN_EMERG"hello_read\r\n");
    return 0;
}

int hello_init(void)
{
    devNum = MKDEV(reg_major,reg_minor);
    if(OK == register_chrdev_region(devNum, subDevNum, "helloworld"))
    {
        printk(KERN_EMERG"register chrdev region ok \n");
    }
    else 
    {
        printk(KERN_EMERG"register chrdev region error \n");
        return ERROR;
    }
    printk(KERN_EMERG"hello driver init \n");
    gDev = kzalloc(sizeof(struct cdev), GFP_KERNEL);
    gFile = kzalloc(sizeof(struct file_operations), GFP_KERNEL);
    gFile->open = hello_open;
    gFile->read = hello_read;
    gFile->write = hello_write;
    gFile->release  = hello_close;
    gFile->owner = THIS_MODULE;
    cdev_init(gDev, gFile);
    cdev_add(gDev, devNum, 3);

    //sema_init(&sema, 1);
    spin_lock_init(&count_lock);
    return 0;
}

void __exit hello_exit(void)
{
    cdev_del(gDev);
    unregister_chrdev_region(devNum,subDevNum);
    return ;
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");

