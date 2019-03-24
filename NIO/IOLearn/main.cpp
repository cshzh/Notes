#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cerrno>
#include <cstring>

int main() {

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

    return 0;
}