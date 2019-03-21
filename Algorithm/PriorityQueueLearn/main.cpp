#include <iostream>
#include <algorithm>
#include <queue>

class item {
public:
    int order;
    int value;

    item(int order, int value) : order(order), value(value) {}


};

struct cmp {
    bool operator()(const item &item1, const item &item2) {
        return item1.value < item2.value ;
    }
};

int main() {
    std::priority_queue<item, std::vector<item>, cmp> queue;

    queue.push(item(1, 66));

    queue.push(item(2, 44));
    queue.push(item(3, 55));

    queue.push(item(4, 44));
    queue.push(item(5, 22));
    queue.push(item(6, 44));
    queue.push(item(7, 33));

    queue.push(item(8, 22));
    queue.push(item(9, 22));

    queue.push(item(10, 44));

    while (!queue.empty()) {
        auto top = queue.top();
        std::cout << top.value << " " << top.order << std::endl;
        queue.pop();
    }
    return 0;
}