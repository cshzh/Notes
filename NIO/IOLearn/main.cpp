#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cerrno>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>

void ReadFile();

void CreateServer();

void CreateClient();

int main() {
    CreateServer();

    CreateClient();

//    ReadFile();

    return 0;
}

/**
 * 创建客户端从网上获取内容
 */
void CreateClient() {
    //TODO
}

/**
 * 创建服务器返回客户端的输入并加上当前时间
 */
void CreateServer() {
    //TODO
}

/**
 * 读取CMakeLists文件
 */
void ReadFile() {
    int fd = open("/home/hui/Projects/Notes/NIO/IOLearn/CMakeLists.txt", O_RDONLY, 0);

    if (fd < 0) {
        printf("open file fail.\n");
        printf("%s\n", strerror(fd));
    } else {
        char buf[1024] = {};

        long length = read(fd, buf, 1024);
        printf("%s\n", buf);

        close(fd);
    }
}