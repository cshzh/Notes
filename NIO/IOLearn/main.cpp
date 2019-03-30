#include <iostream>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>

void read_by_stdio();

void read_by_unix();

int main() {
    printf("%s\n", getenv("HOME"));

    std::ofstream outfile("test.txt");
    for (int i = 0; i < 4096; i++) {
        outfile << 'a';
    }

    outfile << 'b';


    printf("******read_by_unix******\n");
    read_by_unix();

    printf("\n");
    printf("******read_by_stdio******\n");
    read_by_stdio();

    return 0;
}

/**
 * 读取CMakeLists.txt文件
 * 使用UNIX系统的文件I/O函数
 */
void read_by_unix() {
    char buf[1024] = {0};
    auto fd = open("../CMakeLists.txt", O_RDONLY);


    ssize_t length = -1;
    while ((length = read(fd, buf, 1024)) > 0) {
        buf[length] = '\0';
        printf("%s", buf);
    }
    close(fd);
}

/**
 * 读取CMakeLists.txt文件
 * 使用stdio库中函数读文件
 */
void read_by_stdio() {
    char buf[1024];
    auto pFile = fopen("../CMakeLists.txt", "r");
    while (NULL != fgets(buf, 1024, pFile)) {
        printf("%s", buf);
    }
}