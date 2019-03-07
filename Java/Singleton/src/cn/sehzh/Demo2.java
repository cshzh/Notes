package cn.sehzh;

/**
 * 饱汉式
 * 默认实现是不符合多线程安全的，需要使用synchronized同步块
 */
public class Demo2 {
    private static Demo2 demo2;

    private Demo2() {

    }

    public static synchronized Demo2 getInstance() {
        if (demo2 == null) {
            demo2 = new Demo2();
        }
        return demo2;
    }
}
