//
// Created by hui on 19-4-10.
//

#ifndef SELECTLEARN_SERVER_H
#define SELECTLEARN_SERVER_H

#include <iostream>
#include <list>

extern "C" {
#include <csapp/csapp.h>
}

struct TP {
    int connfd;
    char *addr;
    int port;
};

/**
 * 监听端口，对于每个连接的客户端，第一次连接时，向客户端发送hello，以及当前时间，
 * 以后对于客户端的每次发送的内容，返回客户端的发送内容以及当前时间。
 * 将每次收到内容以及发送的内容打印在控制台上。
 * 当收到控制台传来的中断信号时，断开所有打开的连接并关闭子进程
 */
class Server {
public:
    void Run() {
        fd_set read_set, ready_set;

        char listen_port[] = "8080";
        int listen_fd, connfd;
        std::list<TP> fd_list;

        socklen_t clientlen;
        sockaddr_storage client_addr;

        listen_fd = Open_listenfd(listen_port);

        FD_ZERO(&read_set);
        FD_SET(listen_fd, &read_set);

        connfd = listen_fd;
        while (true) {

            ready_set = read_set;
            Select(connfd + 1, &ready_set, NULL, NULL, NULL);

            // 监听的端口
            if (FD_ISSET(listen_fd, &ready_set)) {
                clientlen = sizeof(sockaddr_storage);
                connfd = Accept(listen_fd, (SA *) &client_addr, &clientlen);
                FD_SET(connfd, &read_set);

                sockaddr_in *sockaddrIn = (sockaddr_in *) &client_addr;
                char *cur_client_addr = inet_ntoa(sockaddrIn->sin_addr);
                int port = ntohs(sockaddrIn->sin_port);

                fd_list.push_back({connfd, cur_client_addr, port});

                // 打印连接的客户端
                printf("%s:%d connect\n", cur_client_addr, port);

                // 主动发送 "hello"
                const char *HELLO_STR = "hello";
                if (send(connfd, HELLO_STR, strlen(HELLO_STR), 0) < 0) {
                    fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                    exit(3);
                }

            }

            // 连接的客户端
            for (auto begin = fd_list.begin(); begin != fd_list.end();) {
                auto tp = *begin;
                if (FD_ISSET(tp.connfd, &ready_set)) {
                    char buf[1024];
                    char *cur_client_addr = tp.addr;
                    int cur_client_port = tp.port;

                    // TODO 使用while读取多段数据
                    // 读取客户端的数据
                    int length = recv(tp.connfd, buf, 1024, 0);
                    if (length < 0) {
                        // 发生错误
                        Close(tp.connfd);
                        fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                        exit(3);
                    } else if (0 == length) {
                        // 客户端断开连接
                        Close(tp.connfd);
                        printf("%s:%d disconnected\n", cur_client_addr, cur_client_port);
                        FD_CLR(tp.connfd, &read_set);
                        begin = fd_list.erase(begin);
//                        exit(3);
                    } else {
                        // 将读取到的数据输出到控制台
                        printf("recv(%s:%d): %s\n", cur_client_addr, cur_client_port, buf);

                        // 将数据返回给客户端
                        if (send(tp.connfd, buf, strlen(buf), 0) < 0) {
                            fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
                            exit(3);
                        }
                        begin++;
                    }
                } else {
                    begin++;
                }
            }
        }
    }
};

#endif // SELECTLEARN_SERVER_H
