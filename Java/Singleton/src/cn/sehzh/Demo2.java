package cn.sehzh;

/**
 * 饱汉式
 * 默认实现是不符合多线程安全的，需要使用synchronized同步块
 */
public class Demo2 {
    private static Demo2 demo1;

    private Demo2() {

    }

    public static synchronized Demo2 getInstance() {
        if (demo1 == null) {
            demo1 = new Demo2();
        }
        return demo1;
    }
}
