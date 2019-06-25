//
// Created by hui on 19-6-24.
//

#ifndef HASHMAP_HASH_MAP_H
#define HASHMAP_HASH_MAP_H

class hash_map {
public:
    hash_map() : _length(8), _size(0) {
        _data = new Node[8];
    }

    void put(int key, int value);

    int get(int key);

    void erase(int key);

    int size();

    ~hash_map() {
        if (nullptr != _data) {
            for (int i = 0; i < _length; ++i) {
                Node *pNode = &_data[i];
                while (nullptr != pNode->next) {
                    auto tmp = pNode->next->next;

                    delete pNode->next;

                    pNode->next = tmp;
                }
            }

            delete[]_data;
            _data = nullptr;
        }
    }

private:
    int idx_for_length(int key) {
        return _int_hash_functor(key) % _length;
    }

    void resize();

    struct Node {
        int key;
        int value;
        Node *next;

        explicit Node(int key = 0, int value = 0) : key(key), value(value), next(nullptr) {}
    };

    Node *_data;
    int _length;
    int _size;
    std::hash<int> _int_hash_functor;
};

void hash_map::put(int key, int value) {
    if (_size == _length) {
        resize();
    }

    int idx = idx_for_length(key);

    Node *pNode = &_data[idx];
    while (nullptr != pNode->next) {
        // node exists
        if (key == pNode->next->key) {
            pNode->next->value = value;
            return;
        }
        pNode = pNode->next;
    }

    // new node
    pNode = new Node(key, value);
    pNode->next = _data[idx].next;
    _data[idx].next = pNode;

    ++_size;
}

int hash_map::get(int key) {
    int idx = idx_for_length(key);
    Node *pNode = &_data[idx];
    while (nullptr != pNode->next) {
        if (pNode->next->key == key) {
            return pNode->next->value;
        }
        pNode = pNode->next;
    }
    return -1;
}

int hash_map::size() {
    return _size;
}

void hash_map::erase(int key) {
    int idx = idx_for_length(key);
    Node *pNode = &_data[idx];
    while (nullptr != pNode->next) {
        if (pNode->next->key == key) {
            auto tmp = pNode->next->next;

            delete pNode->next;

            pNode->next = tmp;
            --_size;
            return;
        }
        pNode = pNode->next;
    }
}

void hash_map::resize() {
    Node *old_data = this->_data;
    int old_length = this->_length;

    this->_length = (this->_length << 1);
    this->_data = new Node[this->_length];
    this->_size = 0;

    if (nullptr != old_data) {
        for (int i = 0; i < old_length; ++i) {
            Node *pNode = &old_data[i];
            while (nullptr != pNode->next) {
                auto tmp = pNode->next->next;

                this->put(pNode->next->key, pNode->next->value);
                delete pNode->next;

                pNode->next = tmp;
            }
        }

        delete[]old_data;
        old_data = nullptr;
    }
}

#endif //HASHMAP_HASH_MAP_H
