#include <iostream>
#include <cstring>
#include <memory>
#include <bits/shared_ptr.h>

using namespace std;

class B;

class A {
public:
    A() : m_a(5) {};

    ~A() {
        cout << " A is destroyed" << endl;
    }

    void PrintSpB();

    shared_ptr<B> m_sptrB;
    int m_a;
};

class B {
public:
    B() : m_b(10) {};

    ~B() {
        cout << " B is destroyed" << endl;
    }

    shared_ptr<A> m_sptrA;
    int m_b;
};


int main() {
    shared_ptr<B> sptrB(new B);
    shared_ptr<A> sptrA(new A);
    sptrB->m_sptrA = sptrA;
    sptrA->m_sptrB = sptrB;
}