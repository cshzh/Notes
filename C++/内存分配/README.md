# 内存分配

```c++
// new expression
string * sp = new string("innitialized");
```

当使用**new 表达式**，发生三个步骤

1. 调用名为operator new的标准库函数，分配足够大的原始的未类型化的内存，以保存指定类型的一个对象
2. 运行该类型的一个构造函数，用指定初始化式构造对象
3. 返回新分配并构造的对象的指针

**new表达式与operator new函数：因为new(或delete)表达式与标准库函数同名，所以二者容易混淆。**



```c++
delete sp;
```

当使用delete表达式时，发生两个步骤

1. 对sp所指向的对象调用析构函数
2. 通过调用名为operator delete的标准库函数释放对象所占用的内存



分配和释放未构造的**原始内存**

- allocator类
- 标准库中的operator new 和 operator delete

在原始内存中构造和撤销**对象**

- allocator类中construct和destroy成员
- 定位new表达式(placement new expression)
- 直接调用对象的析构函数
- 算法uninitialized_fill和uninitialized_copy

### allocator类

```c++
#include <bits/stdc++.h>

class Stu {
public:
    int age;
    std::string name;

    Stu(int age, const std::string &name) : age(age), name(name) {
        printf("constructor\n");
    }

    Stu(const Stu &stu) {
        printf("copy constructor\n");
        this->age = stu.age;
        this->name = stu.name;
    }

    Stu &operator=(const Stu &stu) {
        printf("assign operator\n");
        this->name = stu.name;
        this->age = stu.age;
    }

    void show() {
        printf("age:{%d} name:{%s}\n", age, name.c_str());
    }

    virtual ~Stu() {
        printf("destructor\n");
    }
};

int main() {
    Stu stu = {18, "hzh"};
    Stu *p;

    std::allocator<Stu> a;

    p = a.allocate(1);
    // 调用复制构造函数
    a.construct(p, stu);
    p->show();
    a.destroy(p);
    a.deallocate(p, 1);

    return 0;
}
```



## 标准库中的operator new 和 operator delete

### 定位new 表达式

```c++
int main() {
    Stu *p;

    p = static_cast<Stu *>(operator new(sizeof(Stu)));
    // 任意构造函数
    new(p)Stu("hzh");
    p->show();
    p->~Stu();
    operator delete(p);

    return 0;
}
```

