#### 环境搭建
1. 源码下载
    * 地址1(2.6版本)：git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux-2.6.git
    * 

2. 内核源码树
    * 基于2.6版本
        1. arch 特定体系结构的源码
        2. block 块设备I/O层
        3. crypto 加密API
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

3. 内核编译和安装
    * 配置内核
        1. 驱动程序一般都是3in1的配置项(yes,no 或module，module表示以ko形式动态插入到内核中)
        2. 配置选项可以是字符串或整数,比如可以指定静态分配数组的大小
        3. 
    * 减少编译的垃圾信息
    * 安装新内核
    * 
#### 进程
1.   
#### 内存
#### IO操作
#### 驱动模型
#### 参考资料
1. 《Linux内核设计与实现》
2. 《深入理解Linux内核架构》
3. 《深入理解Linux设备驱动》
4. 《Linux设备驱动程序开发》
5. 《韦东山Linux视频》
6. 《Linux内核开发100讲》 简说linux，哔哩哔哩
