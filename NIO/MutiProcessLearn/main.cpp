#include <iostream>

int main() {
    pid_t pid = Fork();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}