//
// Created by hui on 19-4-10.
//

#ifndef MUTIPROCESSLEARN_CLIENT_H
#define MUTIPROCESSLEARN_CLIENT_H

#include <iostream>
#include <cstring>
#include <string>

extern "C" {
#include <csapp/csapp.h>
}

/**
 * 从控制台获取输入，将客户的输入发送到服务器
 * 连接服务器，从服务器读取返回的结果，将结果打印到控制台。
 * 实现思路：两个进程，交互进程和网络进程
 */
class Client {
public:
    void Run() {
        char host[] = "127.0.0.1";
        char port[] = "8080";
        // 连接服务器
        int fd = Open_clientfd(host, port);

        int pid = Fork();
        // Fork
        if (0 == pid) {
            // 网络进程（子进程）从服务器读取数据
            // 网络进程将服务器返回的数据打印到控制台
            while (true) {
                char buf[1024] = {};
                if (recv(fd, buf, 1024, 0) < 0) {
                    Close(fd);
                    fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                    exit(2);
                }
                printf("%s\n", buf);
            }
            exit(0);
        } else {
            // 交互进程（父进程）从控制台读取数据
            // 交互进程将用户的输入发送到服务器
            while (true) {
                char buf[1024] = {};

                // TODO 收到中断时主动断开打开的连接
                fgets(buf, 1024, stdin);

                int length = strlen(buf);
                buf[length - 1] = '\0';
                if (send(fd, buf, length, 0) < 0) {
                    Close(fd);
                    fprintf(stderr, "%s: %s\n", "parent process", strerror(errno));
                    exit(3);
                }
            }

            Wait(nullptr);
        }
    }
};


#endif //MUTIPROCESSLEARN_CLIENT_H
