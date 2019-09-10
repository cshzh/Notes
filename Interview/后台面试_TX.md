# 后台面试解答 

## C++

- 重载overload,覆盖(重写)override,隐藏(重定义)overwrite,这三者之间的区别 [类员函数的重载、覆盖和隐藏](https://www.cnblogs.com/marshhu/p/3435589.html)

- STL的vector/map实现原理?迭代器失效场景

## Linux

- 调试工具gdb/strace/lstrace/tcpdump
- 性能工具gprof [linux高级工具命令(三)使用gprof和oprofile查找性能瓶颈](https://www.cnblogs.com/9sheng/articles/2684248.html)
- [详解mpstat、iostat、sar、vmstat命令的使用](https://blog.csdn.net/qq_39591494/article/details/78418162)

## Network

- [select、poll、epoll之间的区别(搜狗面试)](https://www.cnblogs.com/aspirant/p/9166944.html)

- 描述一下阻塞/非阻塞,同步/异步（参考UNIX网络编程 卷1 第6章）

> io多路复用阻塞在select上，而不是阻塞在send，recv上。优势在于可以等多个描述符就绪。

[深入浅出HTTPS工作原理](https://blog.csdn.net/wangtaomtk/article/details/80917081)