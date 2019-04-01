//
// Created by hui on 19-4-1.
//

#ifndef SINGLETON_SINGLETON_H
#define SINGLETON_SINGLETON_H

#define AGE 18

#include <iostream>

class Singleton {
public:
    static Singleton &GetInstance() {
        // TODO 考虑多线程安全问题
        static Singleton instance(AGE);
        return instance;
    }

    ~Singleton() {
        printf("Destruct Singleton\n");
        delete data;
    }

    void SetData(int data) {
        *this->data = data;
    }

    void Show() {
        printf("data: %d\n", *this->data);
    }


private:
    Singleton(int data) { this->data = new int(data); }

    int *data;
public:
    Singleton(const Singleton &) = delete;

    Singleton &operator=(const Singleton &) = delete;

};


//Singleton *Singleton::instance = nullptr;

#endif //SINGLETON_SINGLETON_H
