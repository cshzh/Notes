# CSAPP读书笔记

![运行时内存映像](./运行时内存映像.png)

[Data_segment](https://en.wikipedia.org/wiki/Data_segment#Data)

.data: 拥有预定值的全局变量和静态变量，可修改

.bss:未初始化数据，包含初始化为0或者没有在代码中没有显式初始化的的全局变量或者静态变量



.init :定义了一个小函数，叫做_init,程序初始化代码会用到

.text：代码段，包含可执行指令，通常是只读并且固定大小的

.rodata: 全局范围	