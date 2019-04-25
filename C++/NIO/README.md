# 网络编程

![基于套接字的网络应用](./IOLearn/基于套接字的网络应用.png)

```c
// IP address structure
struct in_addr {
    unit32_t s_addr; // Address in network byte order(big-endian)
}

// IP socket address structure
struct sockaddr_in {
    uint16_t       sin_family;  // Protocol family (always AF_INET)
    uint16_t       sin_port;    // Port number in network byte order
    struct in_addr sin_addr;    // IP address in network byte order
    unsigned char  sin_zero[8]; // Pad to sizeof(struct sockaddr)
}

// Generic socket address structure(for connect, bind, and accept)
struct sockaddr {
    uint16_t sa_family;    // Protocol family
    char     sa_data[14];  // Address data
}

```

***_in 后缀是互联网络(internet)的缩写***

`socket`函数 : 此函数返回的描述符仅是部分打开的，还不用于读写。

`connect`函数 : 客户端通过connect函数建立和服务器的连接。

服务器通过`bind`, `listen`, 和`accept`函数来建立与客户端的连接。

`bind`函数

`listen`函数

`accept`函数



getaddrinfo函数

```c
int getaddrinfo(const char *host, const char *service,
               const struct addrinfo *hints);
void freeaddrinfo(struct addrinfo *result);
const char *gai_strerror(int errocode);
```

`hints`是一个`addrinfo`结构，提供对`getaddrinfo`返回的套接字地址列表的更好控制。



# 并发编程

## 基于进程的并发服务器

## 基于I/O多路复用的并发编程

[select、poll、epoll之间的区别总结](https://www.cnblogs.com/Anker/p/3265058.html)

### select 

```c++
int select(int nfds, fd_set *readfds, fd_set *writefds,
	fd_set *exceptfds, struct timeval *timeout);

void FD_CLR(int fd, fd_set *set);
int  FD_ISSET(int fd, fd_set *set);
void FD_SET(int fd, fd_set *set);
void FD_ZERO(fd_set *set);
```

> select() can monitor only file descriptors numbers that are less than FD_SETSIZE; poll(2) does not have this limitation. 

### poll

```c++
int poll(struct pollfd *fds, nfds_t nfds, int timeout);

struct pollfd {
               int   fd;         /* file descriptor */
               short events;     /* requested events */
               short revents;    /* returned events */
           };
```

### epoll

I/O事件通知机制

> Level-triggered and edge-triggered
> 

```c++
int epoll_create(int size);
int epoll_create1(int flags);
```


```c++
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
```

```c++
int epoll_wait(int epfd, struct epoll_event *events,
               int maxevents, int timeout);
int epoll_pwait(int epfd, struct epoll_event *events,
               int maxevents, int timeout,
               const sigset_t *sigmask);
```



### 比较

> select的缺点：
>
> 1. 单个进程能够监视的文件描述符的数量存在最大限制，通常是1024，当然可以更改数量，但由于select采用轮询的方式扫描文件描述符，文件描述符数量越多，性能越差；(在linux内核头文件中，有这样的定义：#define __FD_SETSIZE    1024)
> 2. 内核 / 用户空间内存拷贝问题，select需要复制大量的句柄数据结构，产生巨大的开销；
> 3. select返回的是含有整个句柄的数组，应用程序需要遍历整个数组才能发现哪些句柄发生了事件；
> 4. select的触发方式是水平触发，应用程序如果没有完成对一个已经就绪的文件描述符进行IO操作，那么之后每次select调用还是会将这些文件描述符通知进程。
>
> 相比select模型，poll使用链表保存文件描述符，因此没有了监视文件数量的限制，但其他三个缺点依然存在。
>
> 拿select模型为例，假设我们的服务器需要支持100万的并发连接，则在__FD_SETSIZE 为1024的情况下，则我们至少需要开辟1k个进程才能实现100万的并发连接。除了进程间上下文切换的时间消耗外，从内核/用户空间大量的无脑内存拷贝、数组轮询等，是系统难以承受的。因此，基于select模型的服务器程序，要达到10万级别的并发访问，是一个很难完成的任务。

[高并发网络编程之epoll详解](https://blog.csdn.net/shenya1314/article/details/73691088)

[Linux面试必知: 一句话讲透epoll](https://blog.csdn.net/qq_37654024/article/details/57069246)



## 基于线程的并发编程

### 基于线程的事件驱动编程



