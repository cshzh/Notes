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

int main() {
    const char *src = "128.2.194.242";
    int *dst = new int{};
    printf("%s\n", get_current_dir_name());

    if (inet_pton(AF_INET, src, dst) > 0) {
        printf("%#x\n", *dst);
        printf("%#x\n", htonl(*dst));
        printf("%#x\n", htonl(htonl(*dst)));
    } else {
        printf("%s\n", strerror(errno));
    }

//    ReadFile();

    return 0;
}

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