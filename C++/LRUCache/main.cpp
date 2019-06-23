#include <bits/stdc++.h>

using namespace std;


class LRUCache {
private:
    int capacity;
    list<pair<int, int>> mList;
    unordered_map<int, list<pair<int, int>>::iterator> mMap;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mMap.reserve(capacity + 1);
    }

    int get(int key) {
        if (mMap.end() != mMap.find(key)) {
            auto val = mMap[key]->second;

            mList.erase(mMap[key]);
            mList.push_front(make_pair(key, val));

            mMap[key] = mList.begin();

            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mMap.end() != mMap.find(key)) {
            auto val = mMap[key]->second;

            mList.erase(mMap[key]);
            mList.push_front(make_pair(key, value));

            mMap[key] = mList.begin();

            return;
        }

        mList.push_front(make_pair(key, value));
        mMap[key] = mList.begin();
        if (mList.size() > capacity) {
            mMap.erase(mList.back().first);
            mList.pop_back();
        }
    }
};

void testCase1();

void testCase2();

void testCase3();

int main() {
    LRUCache cache(2);

    cout << cache.get(2);
    cache.put(2, 6);
    cout << cache.get(1);
    cache.put(1, 5);
    cache.put(1, 2);
    cout << cache.get(1);
    cout << cache.get(2);

    // -1 -1 2 6

    cout << endl;

    testCase1();

    testCase2();

    testCase3();

    return 0;
}

void testCase3() {
    LRUCache cache(1);
    cache.put(2, 1);
    cout << cache.get(2);
    cache.put(3, 2);
    cout << cache.get(2);
    cout << cache.get(3);

    // 1 -1 2

    cout << endl;
}

void testCase2() {
    LRUCache cache(1 /* capacity */ );

    cache.put(2, 1);
    cout << cache.get(2); // 1

    cout << endl;
}

void testCase1() {
    LRUCache cache(2 /* capacity */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1);       // returns -1 (not found)
    cout << cache.get(3);       // returns 3
    cout << cache.get(4);       // returns 4

    cout << endl;
}