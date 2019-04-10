#include <iostream>
#include <cstring>
#include <cerrno>

extern "C" {
#include <csapp/csapp.h>
}

void Sighandler(int signum) {
    while (waitpid(-1, nullptr, WNOHANG) > 0) {
        printf("Handler reaped child\n");
    }
}

int main() {
    pid_t pid = -1;

    Signal(SIGCHLD, Sighandler);

    for (int i = 0; i < 3; i++) {
        pid = Fork();
        if (pid == 0) {
            // child
            printf("in child %d\n", i);
            if (i == 2) {
                sleep(10);
            }
            exit(0);
        }
    }

    while (true) {
        printf("in main\n");
        sleep(1);
    }

    return 0;
}