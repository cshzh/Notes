# 智能指针

## 原始指针

不释放会导致内存泄露。

删除同一指针多次会得到未定义行为（*undefined behaviour*），意味着可能正常工作，可能崩溃也可能是发生一些随机的事情。

[https://stackoverflow.com/questions/2746677/what-happens-when-you-deallocate-a-pointer-twice-or-more-in-c](https://stackoverflow.com/questions/2746677/what-happens-when-you-deallocate-a-pointer-twice-or-more-in-c)

## auto_ptr

C++98中使用`auto_ptr`，模板类型

从C++11开始，优先使用`unique_ptr`。

## unique_ptr

c++11中使用`unique_ptr`, `shared_ptr`及`weak_ptr`。

## shared_ptr

## weak_ptr