#### 环境搭建
1. 源码下载
    * 地址1(2.6版本)：git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux-2.6.git
    * 地址2(4.9.120版本)：

2. 内核源码树
    * 基于2.6版本
        1. arch 特定体系结构的源码
        2. block 块设备I/O层
        3. crypto 加密解密相关API
        4. Documentation 内核源码文档
        5. drivers 设备驱动程序
        6. firmware 使用某些驱动程序需要的设备固件
        7. fs VFS和各种文件系统
        8. include 内核头文件
        9. init 内核引导和初始化
        10. ipc  进程间通信代码
        11. kernel 调度等核心子系统
        12. lib 通用内核函数
        13. mm 内存管理子系统和VM
        14. net 网络子系统
        15. samples 示例代码
        16. scripts 编译内核所用的脚本
        17. security Linux安全模块
        18. sound 语音子系统
        19. usr 早期用户空间代码
        20. tools 在Linux开发中有用的工具
        21. virt 虚拟化基础结构
        22. COPYING文件：内核许可证
        23. CREDITS文件：开发了很多内核代码的开发者列表
        24. MAINTAINERS文件：维护者列表，它们负责子系统和驱动程序。
        25. Makefile文件：基本内核的Makefile
    * 基于4.9.229版本
        1. arch 特定体系结构的源码
        2. Documentation 内核文档
        3. init 相当于内核的main函数的入口函数，start_kernel为c代码入口
        4. block 块设备相关
        5. drivers 各类驱动代码
        6. fs 文件系统
        7. ipc 进程通信相关资源
        8. net 网络子系统以及相关net驱动的代码
        9. sound 声卡相关代码
        10. crypto 加密解密相关代码
        11. mm 内存管理相关
        12. scripts 编译内核的相关脚本，其中的gdb主要做内核调试的

3. 内核和busybox的编译和安装
    * 配置内核
        1. (yes,no 或module，module表示以ko形式驱动程序一般都是3in1的配置项动态插入到内核中)
        2. 配置选项可以是字符串或整数,比如可以指定静态分配数组的大小
        3. 通过make menuconfig配置自己设备的实际选项
        4. 
    * 减少编译的垃圾信息

4. 打包文件系统
    * Linux 简说
    * 

5. 使用qemu进行启动(qemu)
    * Linux 简说=>
    qemu-system-x86_64 -kernel ./linux-4.9.229/arch/x86/boot/bzImage -initrd ./busybox-1.33.1/rootfs.img.gz --append "root=/dev/ram init=/linuxrc" -serial file:output.txt
    * 奔跑吧Linux=>


#### 内核空间与用户空间
* 基本概念
- 处理器不同，权限不同
+ x86
    1. 用户空间代码运行在Ring3模式，内核空间代码运行在Ring 0模式

+ arm 
    1. 用户空间代码运行在usr模式，内核空间代码运行在svc模式
- 安全考量

    1. 用户和系统隔离，防止某单一应用崩溃导致整个系统崩溃的问题出现
- 从软件设计思想来看，解除了核心代码和业务逻辑代码的耦合
    1. 内核空间处理相关内存管理，进程管理，进程调度等事情，应用空间处理逻辑业务相关的流程，这样解除了耦合性

- 用户空间到内核空间具体的细节原理
    1. 
    
* x86段页式内存管理体系
1. 
2. 
* arm内存管理体系
1. 

#### 进程
1. 基本概念
    
2. 进程管理

3. demo验证

#### 内核中的同步与互斥
* 内联汇编
1. 

* 原子操作原理
1. atomic.h中定义，路径为arch\arm\include\asm\atomic.h
2. 有两种方式：
    * 小于ARMV6架构的指令集（不支持SMP，多个cpu的架构）
        1. 关闭中断
        2. 变量操作
        3. 恢复中断(可能打开，也可能关闭)
    * 大于等于ARMV6架构的指令集(支持SMP)
        1. 使用内联汇编进行操作
        2. 
        3. 
        4. 
3. 

* Linux内核锁机制介绍
1. 自旋锁(spin_lock)
    * 多cpu互斥访问同一个临界资源
    * 接口为：spin_lock, spin_unlock
    * 当某一个cpu已经使用了spin_lock，另一个cpu1来访问时，会等待cpu0释放spin_lock
    * 临界区代码需要尽可能的少
    * 代码实现
        
2. 睡眠锁
    * 
    * 
3. 信号量(semaphore)
    * 可以由不同的进程(线程)来获取和释放
    * 
    * 
4. 互斥锁 mutex
    * 只能由当前进程(线程)来获取和释放

* 同步场景
1. 进程与进程的同步机制-信号量(semaphore)
+ 使用场景
    - 多个进程对同一个资源进行访问
+ 原理
    - 
+ 源码解析
+ 与互斥锁的区别
    - 
2. 

* 互斥场景(mutex)
1. 只能由当前进程来获取和释放

#### 内存
#### IO操作

#### 驱动模型
* 字符驱动
    1. 
* 块设备驱动
* 其他

#### 参考资料
1. 《Linux内核设计与实现》
2. 《深入理解Linux内核架构》
3. 《深入理解Linux设备驱动》
4. 《Linux设备驱动程序开发》
5. 《韦东山Linux视频》
6. 《Linux内核开发100讲》 简说linux，哔哩哔哩
