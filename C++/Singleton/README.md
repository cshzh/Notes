# C++实现单例



## 对一个指针多次delete

**undefined behavior**

```c++
    int *a, *b;
    a = new int[256];
//    a = new int[512];
    b = a;
    printf("*a={%d}\n", *a);
    printf("*b={%d}\n", *b);
    printf("a={%p}\n", a);
    printf("b={%p}\n", b);
    delete[] a;
//    delete[] a;
    delete[] b;
```

当`a = new int[256]`时，两次`delete`并不会报错，程序可以正常运行，正常退出；

而当`a = new int[512]`时，会报`double free or corruption (!prev)`。

g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0