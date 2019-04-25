//
// Created by hui on 19-4-10.
//

#ifndef POLLLEARN_SERVER_H
#define POLLLEARN_SERVER_H

#include <iostream>
#include <map>
#include <poll.h>
#include <climits>

extern "C" {
#include <csapp/csapp.h>
}

struct TP {
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
private:
    static const int MAX_LENGTH = 1024;

public:
    void Run() {
        char listen_port[] = "8080";
        int listen_fd, connfd;
        int maxi, nready;
        std::map<int, TP> map;
        pollfd clients[1024];

        socklen_t clientlen;
        sockaddr_storage client_addr;

        listen_fd = Open_listenfd(listen_port);
//
//        FD_ZERO(&read_set);
//        FD_SET(listen_fd, &read_set);

        clients[0].fd = listen_fd;
        clients[0].events = POLLIN;
        for (int i = 1; i < 1024; i++) {
            clients[i].fd = -1;
        }
        maxi = 0;

        connfd = listen_fd;
        while (true) {

            nready = poll(clients, maxi + 1, INFINITY);

            // 监听的端口
            if (clients[0].revents & (POLLIN | POLLERR)) {
                clientlen = sizeof(sockaddr_storage);
                connfd = Accept(listen_fd, (SA *) &client_addr, &clientlen);

                // TODO 1024
                for (int i = 1; i < 1024; i++) {
                    if (clients[i].fd < 0) {
                        clients[i].fd = connfd;
                        clients[i].events = POLLIN;
                        if (i > maxi) {
                            maxi = i;
                        }
                        break;
                    }
                }

                sockaddr_in *sockaddrIn = (sockaddr_in *) &client_addr;
                char *cur_client_addr = inet_ntoa(sockaddrIn->sin_addr);
                int port = ntohs(sockaddrIn->sin_port);

                map[connfd] = {cur_client_addr, port};

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
            for (int i = 1; i <= maxi; i++) {
                if (clients[i].fd < 0) {
                    continue;
                }

                if (clients[i].revents & (POLLIN | POLLERR)) {
                    auto connfd = clients[i].fd;
                    auto tp = map[connfd];

                    char buf[MAX_LENGTH];
                    char *cur_client_addr = tp.addr;
                    int cur_client_port = tp.port;

                    // TODO 使用while读取多段数据
                    // 读取客户端的数据
                    int length = recv(connfd, buf, MAX_LENGTH, 0);
                    if (length < 0) {
                        // 发生错误
                        Close(connfd);
                        fprintf(stderr, "%s: %s\n", "recv", strerror(errno));
                        exit(3);
                    } else if (0 == length) {
                        // 客户端断开连接
                        Close(connfd);
                        printf("%s:%d disconnected\n", cur_client_addr, cur_client_port);
                        map.erase(connfd);
                    } else {
                        // 将读取到的数据输出到控制台
                        printf("recv(%s:%d): %s\n", cur_client_addr, cur_client_port, buf);

                        // 将数据返回给客户端
                        if (send(connfd, buf, strlen(buf), 0) < 0) {
                            fprintf(stderr, "%s: %s\n", "send", strerror(errno));
                            exit(3);
                        }
                    }
                }
            }
        }
    }
};

#endif // POLLLEARN_SERVER_H
