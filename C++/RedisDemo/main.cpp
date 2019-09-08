#include <iostream>
#include <cpp_redis/cpp_redis>

int main() {
    cpp_redis::client client;

    client.connect("127.0.0.1", 6379, [](const std::string& host, std::size_t port, cpp_redis::connect_state status) {
        if (status == cpp_redis::connect_state::dropped) {
            std::cout << "client disconnected from " << host << ":" << port << std::endl;
        }
    });

    // same as client.send({ "SET", "hello", "42" }, ...)
    client.set("hello", "42", [](cpp_redis::reply& reply) {
        std::cout << "set hello 42: " << reply << std::endl;
        // if (reply.is_string())
        //   do_something_with_string(reply.as_string())
    });

    client.sync_commit();

    return 0;
}