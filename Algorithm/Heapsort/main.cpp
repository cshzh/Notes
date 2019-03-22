#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>
#include <list>

using namespace std;

void init(std::vector<int> &v);

void show(const std::vector<int> &v);

void heap_sort(int arr[], int length);

void heapify(int arr[], int length);

void siftDown(int arr[], int start, int end);

int main() {
    vector<int> v;

    init(v);

    show(v);

    heap_sort(&v[0], v.size());
//    std::sort(v.begin(), v.end());

    show(v);

    return 0;
}

void heap_sort(int arr[], int length) {
    heapify(arr, length);

    int end = length - 1;
    while (end > 0) {
        std::swap(arr[0], arr[end]);

        end--;
        siftDown(arr, 0, end);
    }
}

void heapify(int arr[], int length) {
    int start = length / 2;

    while (start >= 0) {
        siftDown(arr, start, length - 1);
        start--;
    }
}

void siftDown(int arr[], int start, int end) {
    int root = start;
    int tmp = root;

    int child = 2 * root + 1;
    while (child <= end) {
        if (arr[child] > arr[root]) {
            tmp = child;
        }
        if (child + 1 <= end && arr[child + 1] > arr[tmp]) {
            tmp = child + 1;
        }

        if (tmp == root) {
            break;
        } else {
            std::swap(arr[root], arr[tmp]);
            root = tmp;
            child = 2 * root + 1;
        }
    }
}

void show(const vector<int> &v) {
    for (auto &item:v) {
        cout << item << " ";
    }
    cout << endl;
}

void init(vector<int> &v) {
    v.reserve(32);

    random_device rd;
//    srand(time(NULL));

    for (int i = 0; i < 10; ++i) {
        v.push_back(rd() % 10 + 1);
//        v.push_back(rand() % 10 + 1);
    }
}

