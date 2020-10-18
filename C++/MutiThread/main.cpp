#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

std::mutex mtx;

void show() {
    std::unique_lock<std::mutex> guard(mtx);

    std::cout << "tid: " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::thread thread(show);
    std::thread thread2(show);

    thread.join();
    thread2.join();
    return 0;
}