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
        // TODO 服务器突然关闭，客户端输出大量空行
        char port[] = "8080";

        int listenfd, connfd;
        socklen_t clientlen;
        sockaddr_storage clientaddr;

        Signal(SIGCHLD, Sigchld_handler);
        listenfd = Open_listenfd(port);

        while (true) {
            clientlen = sizeof(sockaddr_storage);
            connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);
            if (0 == Fork()) {
                Close(listenfd);

                sockaddr_in *sockaddrIn = (sockaddr_in *) &clientaddr;
                // 主动发送 "hello"
                char *clientaddr = inet_ntoa(sockaddrIn->sin_addr);
                printf("%s:%d connect\n", clientaddr, ntohs(sockaddrIn->sin_port));
                if (send(connfd, "hello", 1024, 0) < 0) {
                    fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                    exit(3);
                }
                while (true) {
                    char buf[1024];

                    // 读取客户端的数据
                    if (recv(connfd, buf, 1024, 0) < 0) {
                        Close(connfd);
                        fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                        exit(3);
                    }

                    // 将读取到的数据输出到控制台
                    printf("recv(%s:%d): %s\n", clientaddr, ntohs(sockaddrIn->sin_port), buf);

                    // 将数据返回给客户端
                    if (send(connfd, buf, strlen(buf), 0) < 0) {
                        fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                        exit(3);
                    }
                }
            }
            Close(connfd);
        }
    }
};


#endif //MUTIPROCESSLEARN_SERVER_H
