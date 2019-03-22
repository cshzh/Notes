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

void merge_sort(int arr[], int length);

vector<int> ans;

int main() {
    vector<int> v;

    init(v);

    show(v);

    merge_sort(&v[0], v.size());
//    std::sort(v.begin(), v.end());

    show(v);

    return 0;
}

void merge(int arr[], int start, int middle, int end) {
    int i = start;
    int j = middle + 1;

    while (i <= middle && j <= end) {
        if (arr[j] < arr[i]) {
            ans.push_back(arr[j]);
            j++;
        } else {
            ans.push_back(arr[i]);
            i++;
        }
    }
    while (i <= middle) {
        ans.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        ans.push_back(arr[j]);
        j++;
    }

    for (i = start; i <= end; i++) {
        arr[i] = ans[i - start];
    }

    ans.clear();
}

void Msort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        Msort(arr, start, middle);
        Msort(arr, middle + 1, end);

        merge(arr, start, middle, end);
    }
}

void merge_sort(int arr[], int length) {
    Msort(arr, 0, length - 1);
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

