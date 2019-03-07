package cn.sehzh;

/**
 * 双重锁
 */
public class Demo3 {
    private static Demo3 demo1;

    private Demo3() {

    }

    public static Demo3 getInstance() {
        if (demo1 == null) {
            synchronized (Demo3.class) {
                if (demo1 == null) {
                    demo1 = new Demo3();
                }
            }

        }
        return demo1;
    }
}
