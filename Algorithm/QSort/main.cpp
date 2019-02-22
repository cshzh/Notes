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

void quick_sort(int arr[], int low, int high);

int partition(int arr[], int low, int high);

int main() {
    vector<int> v;

    init(v);

    show(v);

//    std::sort(v.begin(), v.end());
    quick_sort(&v[0], 0, v.size() - 1);

    show(v);

    return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
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