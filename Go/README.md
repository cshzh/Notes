# Go语言

- 反对函数和操作符重载
- 支持类、类成员方法、类的组合，反对继承，反对虚函数和虚函数重载。
- 放弃构造函数和析构函数
- 接口非侵入性
- 支持匿名函数和闭包
- 运行goroutine和通道，推荐使用消息

> “不要通过共享内存来通信，而应该通过通信来共享内存。”

```go
// squares返回⼀个匿名函数。
// 该匿名函数每次被调⽤时都会返回下⼀个数的平⽅。
func squares() func() int {
var x int
return func() int {
x++
return x * x
}
}
func main() {
f := squares()
fmt.Println(f()) // "1"
fmt.Println(f()) // "4"
fmt.Println(f()) // "9"
fmt.Println(f()) // "16"
}
```

> 函数值属于**引用类型**，函数值**不可比较**。
>
> Go使用**闭包**（closures）技术实现函数值，Go程序员也把函数值叫做闭包。
>
> **变量的生命周期不由它的作用域决定**：squares返回后，变量x仍然隐式的存在于f中。

## 函数参数传递

| 类型  | 增                                 | 删                                   | 改                           |
| ----- | ---------------------------------- | ------------------------------------ | ---------------------------- |
| 数组  | -                                  | -                                    | 无法直接修改，只能传指针修改 |
| Slice | 无法直接修改，可传指针、可传返回值 | 无法直接修改，需传指针（使用append） | 可直接修改元素               |
| Map   | 可直接修改                         | 可直接修改                           | 可直接修改                   |

### Slice

由三个部分组成：指针、长度和容量

[https://juejin.im/post/5ca2b75f51882543ea4b81c8](https://juejin.im/post/5ca2b75f51882543ea4b81c8)

### Map

```go
m = make(map[string]int)
```

> The `make` function allocates and initializes a hash map data structure and returns a map value that points to it. The specifics of that data structure are an implementation detail of the runtime and are not specified by the language itself. In this article we will focus on the *use* of maps, not their implementation.

[Go maps in action](https://blog.golang.org/go-maps-in-action)

### Chan

### 方法

### 接口

`...interface{}`vs`[]interface{}`

`...interface{}`可变参数

#### 接口值

```go
package main

import (
	"bytes"
	"fmt"
	"io"
)

func foo(out io.Writer) {
	fmt.Println(nil == out)
}

func main() {
	var buff *bytes.Buffer
	fmt.Println(nil == buff)
	var out io.Writer
	out = buff
	fmt.Println(nil == out)
	foo(buff)
}

```

```bash
true
false
false
```

> **一个包含nil指针的接口不是nil接口**

#### 类型断言

`v.(float64)`



## make与new的区别

[golang-make-and-new.html](https://draveness.me/golang/keyword/golang-make-and-new.html)