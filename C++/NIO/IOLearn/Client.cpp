#include <iostream>
#include <cstring>
#include <cerrno>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


#define SERVER_PORT 8080

void CreateClient(int port);


int main() {

    CreateClient(SERVER_PORT);

    return 0;
}

/**
 * 获取用户从命令行的输入，发送到服务器，读取并打印服务器的返回内容
 */
void CreateClient(int port) {
    //TODO
}
