#include <iostream>
#include <cstring>
#include <cerrno>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int Fork();

sighandler_t Signal(int signum, sighandler_t handler);

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

sighandler_t Signal(int signum, sighandler_t handler) {
    sighandler_t sighandler;

    if ((sighandler = signal(signum, handler)) == SIG_ERR) {
        fprintf(stderr, "signal error: %s\n", strerror(errno));
        _exit(1);
    }

    return sighandler;
}

int Fork() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        _exit(1);
    }
    return pid;
}