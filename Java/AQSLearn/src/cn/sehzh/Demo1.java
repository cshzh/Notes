package cn.sehzh;

/**
 * 生产者和消费者
 * 使用wait 和 notifyAll 实现
 */
public class Demo1 {

    public static int item = -1;

    public static void main(String[] args) {

        Thread producer = new Thread(new Producer());
        Thread consumer = new Thread(new Consumer());

        producer.start();
        consumer.start();
    }

    static class Producer implements Runnable {

        @Override
        public void run() {
            while (true) {
                synchronized (Demo1.class) {
                    while (item != -1) {
                        try {
                            Demo1.class.wait();

                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }

                    item = (int) (Math.random() * 10);
                    System.out.println("Produce: " + item);

                    Demo1.class.notifyAll();
                }
            }
        }
    }

    static class Consumer implements Runnable {

        @Override
        public void run() {
            while (true) {
                synchronized (Demo1.class) {
                    while (item == -1) {
                        try {
                            Demo1.class.wait();

                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }

                    System.out.println("Consume: " + item);
                    item = -1;

                    Demo1.class.notifyAll();
                }
            }
        }
    }
}


