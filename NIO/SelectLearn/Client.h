//
// Created by hui on 19-4-10.
//

#ifndef SELECTLEARN_CLIENT_H
#define SELECTLEARN_CLIENT_H

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
private:
    /**
     * 防止产生僵尸进程
     * @param signum
     */
    static void Sigchld_handler(int signum) {
        if (waitpid(-1, nullptr, WNOHANG) > 0) {
            exit(0);
        }
    }

public:

    void Run() {
        fd_set read_set, ready_set;
        char host[] = "127.0.0.1";
        char port[] = "8080";
        // 连接服务器
        int connectedfd = Open_clientfd(host, port);

        FD_ZERO(&read_set);
        FD_SET(STDIN_FILENO, &read_set);
        FD_SET(connectedfd, &read_set);

        while (true) {
            ready_set = read_set;

            Select(connectedfd + 1, &ready_set, NULL, NULL, NULL);
            if (FD_ISSET(STDIN_FILENO, &ready_set)) {
                char buf[1024] = {};

                // TODO 收到中断时主动断开打开的连接
                fgets(buf, 1024, stdin);

                int length = strlen(buf);
                buf[length - 1] = '\0';
                if (send(connectedfd, buf, length, 0) < 0) {
                    Close(connectedfd);
                    fprintf(stderr, "%s: %s\n", "parent process", strerror(errno));
                    exit(3);
                }
            }
            if (FD_ISSET(connectedfd, &ready_set)) {
                char buf[1024] = {};
                int length = recv(connectedfd, buf, 1024, 0);
                if (length < 0) {
                    Close(connectedfd);
                    fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
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

//    void RunByProcess() {
//        char host[] = "127.0.0.1";
//        char port[] = "8080";
//        // 连接服务器
//        int connectedfd = Open_clientfd(host, port);
//
//        // 回收子进程
//        Signal(SIGCHLD, Sigchld_handler);
//
//        int pid = Fork();
//        // Fork
//        if (0 == pid) {
//            // 网络进程（子进程）从服务器读取数据
//            // 网络进程将服务器返回的数据打印到控制台
//            while (true) {
//                char buf[1024] = {};
//                int length = recv(connectedfd, buf, 1024, 0);
//                if (length < 0) {
//                    Close(connectedfd);
//                    fprintf(stderr, "%s: %s\n", "child process", strerror(errno));
//                    exit(2);
//                } else if (0 == length) {
//                    // 服务器已下线
//                    Close(connectedfd);
//                    printf("服务器已下线\n");
//                    exit(1);
//                } else {
//                    printf("%s\n", buf);
//                }
//            }
//        } else {
//            // 交互进程（父进程）从控制台读取数据
//            // 交互进程将用户的输入发送到服务器
//            while (true) {
//                char buf[1024] = {};
//
//                // TODO 收到中断时主动断开打开的连接
//                fgets(buf, 1024, stdin);
//
//                int length = strlen(buf);
//                buf[length - 1] = '\0';
//                if (send(connectedfd, buf, length, 0) < 0) {
//                    Close(connectedfd);
//                    fprintf(stderr, "%s: %s\n", "parent process", strerror(errno));
//                    exit(3);
//                }
//            }
//
//            Wait(nullptr);
//        }
//    }
};


#endif //SELECTLEARN_CLIENT_H
