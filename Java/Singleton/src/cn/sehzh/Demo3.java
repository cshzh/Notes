package cn.sehzh;

/**
 * 双重锁
 */
public class Demo3 {
    // 关于为什么使用volatile
    // http://ibat.xyz/2017/03/10/%E5%8D%95%E4%BE%8B%E6%A8%A1%E5%BC%8F--%E5%8F%8C%E9%87%8D%E6%A3%80%E9%AA%8C%E9%94%81%E7%9C%9F%E7%9A%84%E7%BA%BF%E7%A8%8B%E5%AE%89%E5%85%A8%E5%90%97/
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
