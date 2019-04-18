# 程序编译过程

cpp 预处理，通常生成后缀名为 .i 文件

cc1 编译，生成汇编文件，通常生成后缀名为 .s 的文件 （路径/usr/lib/gcc/x86_64-linux-gnu/7/cc1）

as 汇编器 ，生成可重定位的目标文件，通常后缀名为 .o 

ar 归档，可将多个.o文件归档成一个静态链接库，通常后缀名为 .a，

ld 链接器，可执行的目标文件

# 系统调用与函数调用

系统调用

- 跟踪器`strace`
- man(2)

库函数调用

- 跟踪器`ltrace`
- man(3)

- 含系统调用，库函数`printf`内部使用了系统调用`write`
- 不含系统调用，如`strcpy`等

**现在的系统调用被glibc进行了一次封装。(glibc wrapper)**

不使用glibc调用系统调用`_syscall`

> ​	 _syscall - invoking a system call without library support (OBSOLETE)

库函数调用`fork`内部使用的是`clone`。

> **C library/kernel differences**
>        Since  version  2.3.3, rather than invoking the kernel's fork() system call, the glibc fork() wrapper that is provided as part of the NPTL threading implementation invokes clone(2) with flags that provide the same effect as the traditional system call.  (A call to fork() is equivalent to a call  to  clone(2)
> specifying flags as just SIGCHLD.)  The glibc wrapper invokes any fork handlers that have been established using pthread_atfork(3).



包`libc6-dev`提供头文件`/usr/include/unistd.h`、`/usr/include/fcntl.h`、`/usr/include/stdio.h`等

包`libc6`提供运行时的库文件，如`/lib/x86_64-linux-gnu/libc-2.27.so`、`/lib/x86_64-linux-gnu/ld-2.27.so`、`/lib/x86_64-linux-gnu/libm-2.27.so`等。

包`linux-libc-dev`提供文件`/usr/include/linux/unistd.h`、`/usr/include/linux/fcntl.h`等

# C++静态链接

单独使用`-static-libgcc`并未起作用，需与`-static-libstdc++`一起使用。

```bash
hui@hui-desktop:HelloWorld$ g++ main.cpp
hui@hui-desktop:HelloWorld$ lddtree ./a.out
a.out => ./a.out (interpreter => /lib64/ld-linux-x86-64.so.2)
    libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6
        ld-linux-x86-64.so.2 => /lib64/ld-linux-x86-64.so.2
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6
hui@hui-desktop:HelloWorld$ g++ -static-libgcc main.cpp
hui@hui-desktop:HelloWorld$ lddtree ./a.out 
a.out => ./a.out (interpreter => /lib64/ld-linux-x86-64.so.2)
    libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6
        ld-linux-x86-64.so.2 => /lib64/ld-linux-x86-64.so.2
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6
hui@hui-desktop:HelloWorld$ g++ -static-libstdc++ main.cpp
hui@hui-desktop:HelloWorld$ lddtree ./a.out 
a.out => ./a.out (interpreter => /lib64/ld-linux-x86-64.so.2)
    libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6
    ld-linux-x86-64.so.2 => /lib64/ld-linux-x86-64.so.2
hui@hui-desktop:HelloWorld$ g++ -static-libgcc -static-libstdc++ main.cpp
hui@hui-desktop:HelloWorld$ lddtree ./a.out 
a.out => ./a.out (interpreter => /lib64/ld-linux-x86-64.so.2)
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6
    ld-linux-x86-64.so.2 => /lib64/ld-linux-x86-64.so.2
```

[Linking libstdc++ statically](https://blog.csdn.net/huangkangying/article/details/53485516)

```bash
g++ -static-libgcc main.cpp
g++ -static-libgcc -static-libstdc++ main.cpp
g++ -static-libstdc++ main.cpp
```



# 编译成库文件

## 静态库

```
gcc -c sum.c -o sum.o
ar rcs libsum.a sum.o
gcc -o main main.c -L. -lsum
```

**缺点**

- 每次库更新需要链接
- 对于标准库来说，常用函数的代码会被复制到每个进程的文本段，浪费内存资源

## 共享库 

也被称为共享目标，linux中常用 .so 后缀表示（多个进程共享代码段的单一副本，每个进程会有自己的读/写数据块）

```
gcc -shared -fpic -o libsum.so sum.c
gcc -o main main.c -L. -lsum
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
```

PIC（Position-Independent Code, 位置无关代码) 

传统静态链接

加载时的共享库的动态链接

动态链接器

运行时的共享库的动态链接

```
#include <dlfcn.h>

void *dlopen(const char*filename, int flag);

#include <dlfcn.h>
void *dlsym(void *handle, char *symbol);
```

# ELF文件格式

两种视图：

链接视图(Linking View)：Section

执行视图(Execution View)：Segment

# 重定位

- 重定位节和符号定义
- 重定位节中的符号引用

## 重定位条目

代码的重定位条目放在.rel.text中，已初始化的数据的重定位条目放在.rel.data中。

# 链接

静态链接

## 动态链接

### 地址无关的代码

地址无关代码（PIC, Position-Independent-Code）

基本思想是将指令中那些需要被修改的部分分离出来，跟数据部分放在一起，这样指令部分就可以保持不变，而数据部分可以在每个进程中拥有一个副本。

### 延迟绑定

### 动态链接器自举

动态链接器本身是静态链接的。

```bash
ldd /lib/x86_64-linux-gnu/ld-2.27.so
```

## 显式运行时链接

显式运行时链接(Explicit Run-time Linking)，也叫运行时加载。



# 加载

## 地址随机化

ASLR**(Address Space Layout Randomization)

```bash
cat /proc/sys/kernel/randomize_va_space
```

> - 0 = 关闭
> - 1 = 半随机。共享库、栈、mmap() 以及 VDSO 将被随机化。（留坑，PIE会影响heap的随机化。。）
> - 2 = 全随机。除了1中所述，还有heap。

[Linux下关闭ALSR(地址空间随机化)的方法](https://blog.csdn.net/counsellor/article/details/81543197)

