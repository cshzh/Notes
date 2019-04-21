# C++智能指针

## 原始指针

不释放会导致内存泄露。

删除同一指针多次会得到未定义行为（*undefined behaviour*），意味着可能正常工作，可能崩溃也可能是发生一些随机的事情。

示例：

```c++
    int *a;
//    a = new int[256];
    a = new int[512];

    delete[] a;
    delete[] a;
```

当`a = new int[256]`时，两次`delete`并不会报错，程序可以正常运行，正常退出；

而当`a = new int[512]`时，会报`double free or corruption (!top)`。

g++版本：g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0

## C++98

C++98中使用`auto_ptr`，模板类型

缺点：

- 函数调用返回时内存对象并不会返回

  ```c++
  class Stu {
      int age;
      char *name;
  public:
      Stu() : age(0), name(nullptr) {
      }
  
      Stu(int age, const char *name) {
          this->age = age;
          this->name = new char[1024];
          strcpy(this->name, name);
      };
  
      void Show() {
          printf("age:{%d}, name:{%s}\n", this->age, this->name);
      }
  
      ~Stu() {
          puts("destruct...");
          delete[] name;
          name = nullptr;
      }
  };
  
  void Fun(std::auto_ptr<Stu> ptr1) {
      auto p2 = ptr1;
      p2->Show();
  }
  
  int main() {
      std::auto_ptr<Stu> ptr(new Stu(10, "hzh"));
  
      Fun(ptr);
      ptr->Show();
  
      return 0;
  }
  ```

  在上面的代码中会报`段错误`

- 只能用于单个对象，不能用于对象数组

- 不能与标准容器库中的容器使用，如`list`, `vector`等等。

从C++11开始，优先使用`unique_ptr`。

## C++11

c++11中使用`unique_ptr`, `shared_ptr`及`weak_ptr`。

### shared_ptr

多个共享指针可以引用同一个对象，当最后一个指针失效后内存自动释放。

实现机制类似引用计数

正常使用

```c++
    Stu *stu = new Stu(20, "qwe");
    std::shared_ptr<Stu> ptr(stu);
    auto p2 = ptr;
    auto p3 = p2;
```

出现问题

```c++
    Stu *stu = new Stu(20, "qwe");
    std::shared_ptr<Stu> ptr(stu);
    std::shared_ptr<Stu> ptr2(stu);
```

缺点：循环引用问题

```c++
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
```



### weak_ptr

weak指针提供共享语义但是不提供拥有语义。它是一个类模板

```c++
    std::shared_ptr<Stu> sharedPtr(new Stu(10, "hzh"));
    std::weak_ptr<Stu> weakPtr(sharedPtr);
    printf("%ld\n", weakPtr.use_count());
```

可以解决循环引用问题

```c++
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

    weak_ptr<B> m_sptrB;
    int m_a;
};

class B {
public:
    B() : m_b(10) {};

    ~B() {
        cout << " B is destroyed" << endl;
    }

    weak_ptr<A> m_sptrA;
    int m_b;
};

void A::PrintSpB() {
    if (!m_sptrB.expired()) {
        cout << m_sptrB.lock()->m_b << endl;
    }
}

int main() {
    shared_ptr<B> sptrB(new B);
    shared_ptr<A> sptrA(new A);
    sptrB->m_sptrA = sptrA;
    sptrA->m_sptrB = sptrB;
    sptrA->PrintSpB();
}
```

### unique_ptr

取代原来的`auto_ptr`

可以工作在数组上

```c++
    std::unique_ptr<Stu> ptr(new Stu(20, "qwe"));
    std::unique_ptr<Stu[]> ptr2(new Stu[2]);
```

提供两个管理资源的方法

- `release()`: 只释放拥有关系

- `reset()`: 释放拥有关系，销毁资源



参考：

[https://stackoverflow.com/questions/2746677/what-happens-when-you-deallocate-a-pointer-twice-or-more-in-c](https://stackoverflow.com/questions/2746677/what-happens-when-you-deallocate-a-pointer-twice-or-more-in-c)

[https://www.codeproject.com/Articles/541067/Cplusplus-Smart-Pointers](https://www.codeproject.com/Articles/541067/Cplusplus-Smart-Pointers)