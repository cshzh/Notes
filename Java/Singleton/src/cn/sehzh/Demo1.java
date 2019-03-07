package cn.sehzh;

/**
 * 饿汉式
 */
public class Demo1 {
    private static final Demo1 demo1 = new Demo1();

    // 也可以使用来静态代码块来实现，这样可以包含异常处理

    private Demo1() {

    }

    public static Demo1 getInstance() {
        return demo1;
    }
}
