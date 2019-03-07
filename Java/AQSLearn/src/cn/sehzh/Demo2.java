package cn.sehzh;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * 生产者和消费者 （单个生产者单个消费者单个缓冲区）
 * 使用 lock 和 condition 实现
 */
public class Demo2 {

    public static int item = -1;
    public static final Lock lock = new ReentrantLock();
    public static final Condition condition = lock.newCondition();


    public static void main(String[] args) {
        byte i = 10;
        Thread producer = new Thread(new Producer());
        Thread consumer = new Thread(new Consumer());

        producer.start();
        consumer.start();
    }

    static class Producer implements Runnable {

        @Override
        public void run() {
            while (true) {

                lock.lock();

                try {
                    while (item != -1) {
                        condition.await();
                    }

                    item = (int) (Math.random() * 100);
                    System.out.println("Produce: " + item);

//                    condition.signalAll();
                    condition.signal();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    lock.unlock();
                }

            }
        }
    }


    static class Consumer implements Runnable {

        @Override
        public void run() {
            while (true) {

                lock.lock();

                try {
                    while (item == -1) {
                        condition.await();
                    }

                    System.out.println("Consume: " + item);
                    item = -1;

                    Thread.sleep(1000);

//                    condition.signalAll();
                    condition.signal();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    lock.unlock();
                }
            }
        }

    }
}


