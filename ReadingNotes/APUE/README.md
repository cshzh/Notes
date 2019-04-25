# APUE(Advanced Programming in the Unix Environment)

## Signal（信号）

| Signal  | Value | Action | Comment     |
| ------- | ----- | ------ | ----------- |
| SIGKILL | 9     | Term   | Kill signal |
| SIGTERM | 15    | Term   | Termination |

`SIGTERM`可以被捕获或者忽略，`SIGKILL`无法或者忽略。

```c++
#include <iostream>
#include <signal.h>
#include <unistd.h>

static void sig_hander(int);

int main() {
    if (signal(SIGUSR1, sig_hander) == SIG_ERR) {
        perror("can't catch siguser1");
    }
//    else if (signal(SIGTERM, sig_hander) == SIG_ERR) {
//        perror("can't catch SIGTERM");
//    }

    for (;;) {
        pause();
    }
    return 0;
}

static void sig_hander(int signo) {
    if (signo == SIGUSR1) {
        printf("received SIGUSER1\n");
    } else if (signo == SIGUSR2) {
        printf("received SIGUSER2\n");
    } else if (signo == SIGTERM) {
        printf("received SIGTERM\n");
    } else {
        printf("received signal %d\n", signo);
    }
}
```

## 文件共享

![找开文件的内核数据结构](./找开文件的内核数据结构.png)



对称多处理器（SMP，Symmetrical Muti-Processing）

驱动程序与操作系统

> 驱动程序与操作系统运行有特权级，但它与操作系统保持一定的独立性。
>
> 驱动程序的开发通常由硬件厂商完成。
>
> 操作系统开发者为硬件厂商提供了一系列的接口和框架，凡是按照这个接口和框架开发的驱动程序都可以在操作系统上使用。

Linux中断处理和内核线程

中断处理程序ISR（Interrupt Service Routine）

中断请求

[https://en.wikipedia.org/wiki/Interrupt_request_(PC_architecture)](https://en.wikipedia.org/wiki/Interrupt_request_(PC_architecture))

[https://en.wikipedia.org/wiki/Interrupt_handler](https://en.wikipedia.org/wiki/Interrupt_handler)

