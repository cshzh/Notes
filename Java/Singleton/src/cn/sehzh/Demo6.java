package cn.sehzh;

import java.util.concurrent.atomic.AtomicReference;

/**
 * 使用CAS锁实现
 * http://www.hollischuang.com/archives/1866
 * 注意：此种方式只能保证每次返回的是同一个Demo6对象，不能保证只构造一个Demo6对象
 */
public class Demo6 {
    private static final AtomicReference<Demo6> INSTANCE = new AtomicReference<>();

    private Demo6() {
    }


    public static Demo6 getInstance() {
        for (; ; ) {
            Demo6 demo6 = INSTANCE.get();
            if (demo6 != null) {
                return demo6;
            }

            demo6 = new Demo6();
            if (INSTANCE.compareAndSet(null, demo6)) {
                return demo6;
            }
        }
    }
}
