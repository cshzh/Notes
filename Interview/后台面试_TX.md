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

## database

- mysql怎么实现主从复制的一致性?
- 聚簇索引和非聚簇索引的区别?实现原理
- InnoDB用B+树比B树有什么优势?
- Mysql数据如何恢复到任意时间点?
- 描述一下数据库设计的第1~3范式 [[图文]第六章 数据库设计理论 - 范式（第四五讲）](https://wenku.baidu.com/view/7179d7ae763231126fdb1158.html?from=search) [数据库原理概论 第六章](https://wenku.baidu.com/view/f948b002680203d8cf2f243f)
- 事务的ACID,描述一下?
- 数据库的脏读,幻读,不可重复读出现的原因原理,解决办法?对应的隔离级别有哪些?
- MVCC机制用来解决什么问题? [参考 MySQL技术内幕 6.3.2]() [https://stackoverflow.com/questions/11043712/what-is-the-difference-between-non-repeatable-read-and-phantom-read](https://stackoverflow.com/questions/11043712/what-is-the-difference-between-non-repeatable-read-and-phantom-read)
- CAP/BASE理论听过吗?能描述一下吗? [分布式理论(二)——Base 理论](https://www.jianshu.com/p/9cb2a6fa4e0e)
- NoSQL的数据库接触过吗?Redis?
- Redis有哪些对象?底层是用什么数据结构实现的?
- Redis怎么做过期删除?
- Redis怎么做持久化?RDB和AOF有什么区别?为什么需要重写?
- Redis的主从复制是怎么做的?集群如何处理Shard和Replication?
- Redis的事务是怎么实现的?满足ACID特性吗?达到了什么样的隔离级别?
- 描述一下HBASE的数据倾斜问题?如何解决?
- NewSql听过吗?出现的背景和应用场景是什么?



- 圆上取三个点,这三个点构成锐角三角形的概率多大 [https://wenku.baidu.com/view/657fa4d65901020206409cb4.html](https://wenku.baidu.com/view/657fa4d65901020206409cb4.html)



