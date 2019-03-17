#include <iostream>

using namespace std;

class A  //大小为4
{
public:
    int a;

    virtual string print() { return "In base..."; }
};

class B : virtual public A {
public:
    int b;

    virtual string print() { return "In B..."; }
};

class C : virtual public A {
public:
    int c;

//    string print() override { return "In C..."; }
};

class D : public B, public C {
public:
    int d;

//   virtual string print() { return "In D..."; }
};


int main() {
    A *base = new D();

    //TODO 这里为什么会输出 "In B..."
    cout << base->print() << endl;

    return 0;
}