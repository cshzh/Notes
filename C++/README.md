# C++11常用知识点

## 继承

友元关系不能继承

构造函数与复制构造函数不继承

继承权限控制

- `public`继承，基类成员保持自己的访问级别；

- `protected`继承，基类的`public`成员在派生类中是protected的；

- `private`继承，基类的所有成员在派生类中为`private`的。

在派生类作用域中派生类成员将屏蔽基类成员。**即使函数原型不同，基类成员也会被屏蔽**。



auto 关键字、

for-each 循环、

右值及移动构造函数 + std::forward + std::move + stl 容器新增的 emplace_back() 方法、

[https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used](https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used)

std::chrono 库、

智能指针系列（std::shared_ptr/std::unique_ptr/std::weak_ptr）(智能指针的实现原理一定要知道，最好是自己实现过)、

线程库 std::thread + 线程同步技术库std::mutex/std::condition_variable/std::lock_guard 等、

lamda 表达式（JAVA 中现在也常常考察 lamda 表达式的作用）、

std::bind/std::function 库、其他的就是一些关键字的用法(override、final、delete)，

还有就是一些细节如可以像 JAVA 一样在类成员变量定义处给出初始化值



重载、重写（）、隐藏

林锐. 高质量程序设计指南[M]. 电子工业出版社, 2002.