# Java 实现真正的优先级队列（相同优先级的元素先进先出）

最近在使用 Java 的 PriorityQueue 类的时候发现，PriorityQueue类能保证先输出优先级高的元素，但是对于优先级相同的元素时，它并不能保证先进先出。

示例如下：

```java
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 *        66
 *    44        55
 * 44    22   44    33
 * 22  22  (44)
 */

class MyInteger {
    // 插入顺序
    int order;
    int value;

    public MyInteger(int order, int value) {
        this.order = order;
        this.value = value;
    }

    public void setOrder(int order) {
        this.order = order;
    }

    public void setValue(int value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return "MyInteger{" +
                "order=" + order +
                ", value=" + value +
                '}';
    }
}

public class Main {
    public static void main(String[] args) {
        // 创建一个优先级队列
        PriorityQueue<MyInteger> priorityQueue = new PriorityQueue<>(new Comparator<MyInteger>() {
            @Override
            public int compare(MyInteger o1, MyInteger o2) {
                return o2.value - o1.value;
            }
        });

        // 插入10个元素
        priorityQueue.offer(new MyInteger(1, 66));

        priorityQueue.offer(new MyInteger(2, 44));
        priorityQueue.offer(new MyInteger(3, 55));

        priorityQueue.offer(new MyInteger(4, 44));
        priorityQueue.offer(new MyInteger(5, 22));
        priorityQueue.offer(new MyInteger(6, 44));
        priorityQueue.offer(new MyInteger(7, 33));

        priorityQueue.offer(new MyInteger(8, 22));
        priorityQueue.offer(new MyInteger(9, 22));

        priorityQueue.offer(new MyInteger(10, 44));

        while (!priorityQueue.isEmpty()) {
            // 依次从队列中取出元素并打印
            System.out.println(priorityQueue.poll());
        }
        System.out.println();
    }
}

```

我们先向队列中插入10个元素，并依次从队列中取出元素打印。

输出结果如下：

```
MyInteger{order=1, value=66}
MyInteger{order=3, value=55}
MyInteger{order=2, value=44}
MyInteger{order=4, value=44}
MyInteger{order=10, value=44}
MyInteger{order=6, value=44}
MyInteger{order=7, value=33}
MyInteger{order=9, value=22}
MyInteger{order=5, value=22}
MyInteger{order=8, value=22}

```

注意，对于`value`为`44`的元素，它的输出次序与我们的插入次序不一致，我们的插入次序为`2, 4, 6, 10`，它的输出次序为`2, 4, 10, 6`。

这与我们在课本上学到的定义不太一样。当队列中有多个优先级相同的元素时，我们应该要保证先进先出。

为此，我们增加一个插入时刻`insertTime`，当元素的`value`相同的时候，我们比较元素的插入时刻，先插入的元素插入时刻小，优先级高。

示例代码如下：

```java
import java.time.LocalDateTime;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 *        66
 *    44        55
 * 44    22   44    33
 * 22  22  (44)
 */

class MyInteger {
    int order;
    int value;
    LocalDateTime insertTime;

    public MyInteger(int order, int value, LocalDateTime insertTime) {
        this.order = order;
        this.value = value;
        this.insertTime = insertTime;
    }

    public void setOrder(int order) {
        this.order = order;
    }

    public void setValue(int value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return "MyInteger{" +
                "order=" + order +
                ", value=" + value +
                '}';
    }
}

public class Main {
    public static void main(String[] args) {
        // 创建一个优先级队列
        PriorityQueue<MyInteger> priorityQueue = new PriorityQueue<>(new Comparator<MyInteger>() {
            @Override
            public int compare(MyInteger o1, MyInteger o2) {
                return o2.value == o1.value ? o1.insertTime.compareTo(o2.insertTime) : o2.value - o1.value;
            }
        });

        // 插入10个元素
        priorityQueue.offer(new MyInteger(1, 66, LocalDateTime.now()));

        priorityQueue.offer(new MyInteger(2, 44, LocalDateTime.now()));
        priorityQueue.offer(new MyInteger(3, 55, LocalDateTime.now()));

        priorityQueue.offer(new MyInteger(4, 44, LocalDateTime.now()));
        priorityQueue.offer(new MyInteger(5, 22, LocalDateTime.now()));
        priorityQueue.offer(new MyInteger(6, 44, LocalDateTime.now()));
        priorityQueue.offer(new MyInteger(7, 33, LocalDateTime.now()));

        priorityQueue.offer(new MyInteger(8, 22, LocalDateTime.now()));
        priorityQueue.offer(new MyInteger(9, 22, LocalDateTime.now()));

        priorityQueue.offer(new MyInteger(10, 44, LocalDateTime.now()));

        while (!priorityQueue.isEmpty()) {
            // 依次从队列中取出元素并打印
            System.out.println(priorityQueue.poll());
        }
        System.out.println();
    }
}

```

输出结果：

```
MyInteger{order=1, value=66}
MyInteger{order=3, value=55}
MyInteger{order=2, value=44}
MyInteger{order=4, value=44}
MyInteger{order=6, value=44}
MyInteger{order=10, value=44}
MyInteger{order=7, value=33}
MyInteger{order=5, value=22}
MyInteger{order=8, value=22}
MyInteger{order=9, value=22}
```

**注意:在实际业务代码中还需要考虑线程安全的问题。**

