# LRU 实现的四种方式

## 单链表

```cpp
class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node *next;

        Node(int key, int val) : key(key), val(val), next(nullptr) {}
    };

private:
    int capacity;
    Node *pHead;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // the size of list is key in head node
        pHead = new Node(0, 0);
    }

    int get(int key) {
        Node *pNode = pHead;
        while (nullptr != pNode->next) {
            if (key == pNode->next->key) {
                // found
                auto tmp = pNode->next;
                pNode->next = pNode->next->next;
                tmp->next = pHead->next;
                pHead->next = tmp;

                return pHead->next->val;
            }
            pNode = pNode->next;
        }
        // not found
        return -1;
    }

    void put(int key, int value) {
        Node *pNode = pHead;

        while (nullptr != pNode->next) {
            if (key == pNode->next->key) {
                pNode->next->val = value;
                auto tmp = pNode->next;
                pNode->next = pNode->next->next;
                tmp->next = pHead->next;
                pHead->next = tmp;
                return;
            }
            pNode = pNode->next;
        }
        // not found
        pNode = new Node(key, value);
        pNode->next = pHead->next;
        pHead->next = pNode;
        pHead->key++;
        if (pHead->key > capacity) {
            // remove last node
            pNode = pHead;
            while (nullptr != pNode->next && nullptr != pNode->next->next) {
                pNode = pNode->next;
            }
            auto last = pNode->next;
            pNode->next = nullptr;
            if (nullptr != last) {
                delete last;
                last == nullptr;
            }
            pHead->key = capacity;
        }
    }

    ~LRUCache() {
        delete pHead;
        pHead = nullptr;
    }
};
```

`get`时间复杂度O(n)，`put`时间复杂度O(n)。

## 双向链表实现

```cpp
class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node *before;
        Node *after;

        Node(int key, int val) : key(key), val(val), before(nullptr), after(nullptr) {}
    };

private:
    int capacity;
    Node *pHead;
    Node *pTail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // the size of list is key in head node
        pHead = new Node(0, 0);
        pTail = nullptr;
    }

    int get(int key) {
        Node *pNode = pHead;
        while (nullptr != pNode->after) {
            if (key == pNode->after->key) {
                // found
                auto tmp = pNode->after;

                if (nullptr != tmp->after) {
                    tmp->after->before = tmp->before;
                } else {
                    // tail
                    if (pHead != tmp->before) {
                        pTail = tmp->before;
                    }
                }

                tmp->before->after = tmp->after;

                if (nullptr != pHead->after) {
                    pHead->after->before = tmp;
                }

                tmp->after = pHead->after;
                tmp->before = pHead;
                pHead->after = tmp;

                return pHead->after->val;
            }
            pNode = pNode->after;
        }
        // not found
        return -1;
    }

    void put(int key, int value) {
        Node *pNode = pHead;

        while (nullptr != pNode->after) {
            if (key == pNode->after->key) {
                // found
                auto tmp = pNode->after;
                tmp->val = value;

                if (nullptr != tmp->after) {
                    tmp->after->before = tmp->before;
                } else {
                    // tail
                    if (pHead != tmp->before) {
                        pTail = tmp->before;
                    }
                }
                tmp->before->after = tmp->after;

                if (nullptr != pHead->after) {
                    pHead->after->before = tmp;
                }

                tmp->after = pHead->after;
                tmp->before = pHead;
                pHead->after = tmp;
                return;
            }
            pNode = pNode->after;
        }
        // not found
        pNode = new Node(key, value);
        pNode->before = pHead;
        pNode->after = pHead->after;

        if (nullptr != pHead->after) {
            pHead->after->before = pNode;
        } else {
            // first node
            pTail = pNode;
        }

        pHead->after = pNode;
        pHead->key++;

        if (pHead->key > capacity) {
            // remove last node
            auto tmp = pTail;

            pTail = pTail->before;
            pTail->after = nullptr;

            delete tmp;
            tmp = nullptr;
        }
    }

    ~LRUCache() {
        delete pHead;
        pHead = nullptr;
    }
};
```

`put`时间复杂度O(n),`get`时间复杂度O(n)。

## unordered_map加双向链表

```cpp
class LRUCache {
    struct Node {
        int key;
        int val;
        Node *before;
        Node *after;

        Node(int key = 0, int val = 0) : key(key), val(val), before(nullptr), after(nullptr) {}

        bool operator==(const Node &rhs) const {
            return key == rhs.key &&
                   val == rhs.val;
        }

        bool operator!=(const Node &rhs) const {
            return !(rhs == *this);
        }
    };

private:
    int capacity;
    unordered_map<int, Node> hashMap;
    int *head;
    int *tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        hashMap.reserve(capacity + 1);
        // the size of list is key in head node
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (hashMap.end() != hashMap.find(key)) {
            Node &cur = hashMap[key];

            if (key != *head) {

                cur.before->after = cur.after;

                if (nullptr != cur.after) {
                    cur.after->before = cur.before;
                } else {
                    // tail
                    *tail = cur.before->key;
                }

                hashMap[*head].before = &cur;

                cur.before = nullptr;
                cur.after = &hashMap[*head];

                *head = key;
            }

            return cur.val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (hashMap.end() != hashMap.find(key)) {
            Node &cur = hashMap[key];

            if (key != *head) {

                cur.before->after = cur.after;

                if (nullptr != cur.after) {
                    cur.after->before = cur.before;
                } else {
                    // tail
                    *tail = cur.before->key;
                }

                hashMap[*head].before = &cur;

                cur.before = nullptr;
                cur.after = &hashMap[*head];

                *head = key;
            }

            cur.val = value;
            return;
        }

        // not found
        if (nullptr == head) {
            hashMap[key] = {key, value};
            head = new int();
            tail = new int();
            *head = key;
            *tail = key;
        } else {
            hashMap[key] = {key, value};

            hashMap[*head].before = &hashMap[key];
            hashMap[key].after = &hashMap[*head];
            hashMap[key].before = nullptr;

            *head = key;

            if (hashMap.size() > this->capacity) {
                int newTail = hashMap[*tail].before->key;

                hashMap[*tail].before->after = nullptr;
                hashMap.erase(*tail);

                *tail = newTail;
            }
        }
    }

    ~LRUCache() {
        if (nullptr != head) {
            delete head;
            head = nullptr;
        }
        if (nullptr != tail) {
            delete tail;
            tail = nullptr;
        }
    }
};
```

`put`函数时间复杂度O(1)，`get`函数时间复杂度O(1)。

## unordered_map加list

```cpp
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
```

`put`函数时间复杂度O(1)，`get`函数时间复杂度O(1)。

leetcode地址:[lru-cache](https://leetcode.com/problems/lru-cache/)