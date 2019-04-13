//
// Created by hui on 19-4-10.
//

#ifndef POLLLEARN_CLIENT_H
#define POLLLEARN_CLIENT_H

#include <iostream>
#include <cstring>
#include <string>
//#include <poll.h>
#include <sys/epoll.h>

extern "C" {
#include <csapp/csapp.h>
}


#define MAX_EVENT 10
epoll_event ev, event[MAX_EVENT];
int nfds, epollfd;

/**
 * 从控制台获取输入，将客户的输入发送到服务器
 * 连接服务器，从服务器读取返回的结果，将结果打印到控制台。
 * 实现思路：使用Poll
 */
class Client {
private:
    static const int MAX_LENGTH = 1024;

public:

    void Run() {

//        pollfd pollfds[1024];

        char host[] = "127.0.0.1";
        char port[] = "8080";
        // 连接服务器
        int connectedfd = Open_clientfd(host, port);

//        pollfds[0].fd = STDIN_FILENO;
//        pollfds[0].events = POLLIN;
//        pollfds[1].fd = connectedfd;
//        pollfds[1].events = POLLIN;
        epollfd = epoll_create1(0);
        if (-1 == epollfd) {
            perror("epoll_create1");
            exit(EXIT_FAILURE);
        }

        ev.events = EPOLLIN;
        ev.data.fd = connectedfd;

        if (epoll_ctl(epollfd, EPOLL_CTL_ADD, connectedfd, &ev) == -1) {
            perror("epoll_ctl: connectedfd");
            exit(EXIT_FAILURE);
        }

        ev.events = EPOLLIN;
        ev.data.fd = STDIN_FILENO;

        if (epoll_ctl(epollfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev) == -1) {
            perror("epoll_ctl: STDIN_FILENO");
            exit(EXIT_FAILURE);
        }

        while (true) {
//            poll(pollfds, 2, INFINITY);
            nfds = epoll_wait(epollfd, event, MAX_EVENT, -1);

            for (int i = 0; i < nfds; ++i) {
                if (event[i].data.fd == STDIN_FILENO) {
                    char buf[MAX_LENGTH] = {};

                    // TODO 收到中断时主动断开打开的连接
                    fgets(buf, MAX_LENGTH, stdin);

                    int length = strlen(buf);
                    buf[length - 1] = '\0';
                    if (send(connectedfd, buf, length, 0) < 0) {
                        Close(connectedfd);
                        fprintf(stderr, "%s: %s\n", "send", strerror(errno));
                        exit(3);
                    }
                }
                if (event[i].data.fd == connectedfd) {
                    char buf[MAX_LENGTH] = {};
                    int length = recv(connectedfd, buf, MAX_LENGTH, 0);
                    if (length < 0) {
                        Close(connectedfd);
                        fprintf(stderr, "%s: %s\n", "recv", strerror(errno));
                        exit(2);
                    } else if (0 == length) {
                        // 服务器已下线
                        Close(connectedfd);
                        printf("服务器已下线\n");
                        exit(1);
                    } else {
                        printf("%s\n", buf);
                    }
                }
            }

        }
    }
};


#endif //POLLLEARN_CLIENT_H
