package cn.sehzh;

/**
 * 双重锁
 */
public class Demo3 {
    // 关于为什么使用volatile， volatile
    private static volatile Demo3 demo3;

    private Demo3() {

    }

    public static Demo3 getInstance() {
        if (demo3 == null) {
            synchronized (Demo3.class) {
                if (demo3 == null) {
                    demo3 = new Demo3();
                }
            }

        }
        return demo3;
    }
}
