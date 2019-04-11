//
// Created by hui on 19-4-10.
//

#ifndef MUTIPROCESSLEARN_SERVER_H
#define MUTIPROCESSLEARN_SERVER_H

#include <iostream>

extern "C" {
#include <csapp/csapp.h>
}

/**
 * 监听端口，对于每个连接的客户端，第一次连接时，向客户端发送hello，以及当前时间，
 * 以后对于客户端的每次发送的内容，返回客户端的发送内容以及当前时间。
 * 将每次收到内容以及发送的内容打印在控制台上。
 * 当收到控制台传来的中断信号时，断开所有打开的连接并关闭子进程
 */
class Server {
public:
    /**
     * 防止产生僵尸进程
     * @param signum
     */
    static void Sigchld_handler(int signum) {
        while (waitpid(-1, nullptr, WNOHANG) > 0);
    }

    void Run() {
        char port[] = "8080";

        int listenfd, connfd;
        socklen_t clientlen;
        sockaddr_storage clientaddr;

        // 回收子进程
        Signal(SIGCHLD, Sigchld_handler);

        listenfd = Open_listenfd(port);

        while (true) {
            clientlen = sizeof(sockaddr_storage);
            connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);
            if (0 == Fork()) {
                Close(listenfd);

                sockaddr_in *sockaddrIn = (sockaddr_in *) &clientaddr;
                char *clientaddr = inet_ntoa(sockaddrIn->sin_addr);

                // 打印连接的客户端
                printf("%s:%d connect\n", clientaddr, ntohs(sockaddrIn->sin_port));

                // 主动发送 "hello"
                const char *HELLO_STR = "hello";
                if (send(connfd, HELLO_STR, strlen(HELLO_STR), 0) < 0) {
                    fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                    exit(3);
                }

                while (true) {
                    char buf[1024];

                    // TODO 使用while读取多段数据
                    // 读取客户端的数据
                    int length = recv(connfd, buf, 1024, 0);
                    if (length < 0) {
                        // 发生错误
                        Close(connfd);
                        fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                        exit(3);
                    } else if (0 == length) {
                        // 客户端断开连接
                        Close(connfd);
                        printf("%s:%d disconnected\n", clientaddr, ntohs(sockaddrIn->sin_port));
                        exit(3);
                    } else {
                        // 将读取到的数据输出到控制台
                        printf("recv(%s:%d): %s\n", clientaddr, ntohs(sockaddrIn->sin_port), buf);

                        // 将数据返回给客户端
                        if (send(connfd, buf, strlen(buf), 0) < 0) {
                            fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                            exit(3);
                        }
                    }
                }
            }
            Close(connfd);
        }
    }
};


#endif //MUTIPROCESSLEARN_SERVER_H
