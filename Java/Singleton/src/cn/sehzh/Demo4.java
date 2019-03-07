package cn.sehzh;

/**
 * 使用静态内部类实现
 * https://www.journaldev.com/1377/java-singleton-design-pattern-best-practices-examples
 */
public class Demo4 {
    private Demo4() {
    }

    private static class SingletonHelper {
        private static final Demo4 INSTANCE = new Demo4();
    }

    public static Demo4 getInstance() {
        return SingletonHelper.INSTANCE;
    }
}
