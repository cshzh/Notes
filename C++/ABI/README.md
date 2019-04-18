# ABI(Application binary interface) Policy and Guidelines

LSB(Linux standard Base)

> LSB是一组ABI接口的定义，它规范了运行环境所需要的类型，宏，变量和函数的二进制接口。

```
hui@hui-desktop:C++$ /lib/x86_64-linux-gnu/libc-2.27.so
GNU C Library (Ubuntu GLIBC 2.27-3ubuntu1) stable release version 2.27.
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.
Compiled by GNU CC version 7.3.0.
libc ABIs: UNIQUE IFUNC
```

```
hui@hui-desktop:C++$ gcc --version
gcc (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0
Copyright (C) 2017 Free Software Foundation, Inc.
```

## The C++ Interface

> **API**: 函数名、参数类型、返回值和副作用
>
> **ABI**：C++源文件由编译器编译成目标文件：编译器对齐对象，mangling命名、通过特殊的机制来支持虚函数。这些细节被称为应用程序二进程接口。（从GCC 3开始，GNU C++编译器开始使用工业标准的C++ ABI, Itanium C++ ABI.）
>
> - 函数调用规范和符号命名
> - 数据类型的代表（大小、对齐、浮点数格式）
> - 目标文件格式（ELF）
> - 程序应该怎么加载，动态链接，符号重定位和线程本地存储
>
> GNU C++编译器的g++有一个编译命令可以在不同的C++ ABI版本中切换。显式命令是通过`-fabi-version`标志。此外，由于副作用，一些g++命令行选项也可以改变ABI。如`-fpack-struct`和`-fno-exception`，详见[Options for Code Generation Conventions](http://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html#Code%20Gen%20Options)
>
> libstdc++版本也会影响到库的ABI
>
> 将这些所有情况结合一下就是成了C++ 标准库的ABI。
>
> library API + compiler ABI = library ABI
>
> 



[https://stackoverflow.com/questions/32443646/if-clang-and-g-are-abi-incompatible-what-is-used-for-shared-libraries-in-bi](https://stackoverflow.com/questions/32443646/if-clang-and-g-are-abi-incompatible-what-is-used-for-shared-libraries-in-bi)

[https://gcc.gnu.org/onlinedocs/libstdc++/manual/abi.html](https://gcc.gnu.org/onlinedocs/libstdc++/manual/abi.html)