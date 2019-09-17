# 并发编程

管程(Monitor):互斥锁＋条件变量

互斥：资源的竞争访问

同步：资源的有序访问

## 同步

|                          | 进程               | 线程               |
| ------------------------ | ------------------ | ------------------ |
| 信号量(Semaphores)       | :heavy_check_mark: | :heavy_check_mark: |
| 互斥锁(Mutexes)          |                    | :heavy_check_mark: |
| 临界段(Critical section) |                    | :heavy_check_mark: |
| 管程(Monitor)            |                    | :heavy_check_mark: |

进程

- 信号量

线程

- 临界区
- 互斥锁
- 条件变量
- 阻塞队列
- CAS无锁



## 通信

进程

- 管道（无名管道、有名管道）
- 共享内存
- 信号量
- 远程过程调用
- 消息队列
- unix socket

线程

- 共享地址空间，直接通过变量就可以了

## 对比

`std::lock_guard` vs `std::unique_lock`

- `lock_guard`无法手动释放锁，`unique_lock`可以手动释放

- 通常使用`lock_guard`，当需要使用到`unique_lock`特有的功能时才使用`unique_lock`

信号量 vs 管程

[https://zhanghuimeng.github.io/post/os-mooc-lecture-18-summary/](https://zhanghuimeng.github.io/post/os-mooc-lecture-18-summary/)

## 参考文献：

1. [https://www.cnblogs.com/549294286/p/3687678.html](https://www.cnblogs.com/549294286/p/3687678.html)
2. [https://www.jianshu.com/p/01ad36b91d39](https://www.jianshu.com/p/01ad36b91d39)
3. [https://www.cnblogs.com/lonelycatcher/archive/2011/12/20/2294161.html](https://www.cnblogs.com/lonelycatcher/archive/2011/12/20/2294161.html)
4. [https://www.cnblogs.com/haippy/p/3284540.html](https://www.cnblogs.com/haippy/p/3284540.html)
5. [https://en.wikipedia.org/wiki/Monitor_%28synchronization%29](https://en.wikipedia.org/wiki/Monitor_%28synchronization%29)
6. [http://jakascorner.com/blog/2016/02/lock_guard-and-unique_lock.html](http://jakascorner.com/blog/2016/02/lock_guard-and-unique_lock.html)