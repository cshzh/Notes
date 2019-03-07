package cn.sehzh;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

/**
 * 生产者和消费者 （多个生产者多个消费者多个缓冲区）
 * 使用  ArrayBlockingQueue 实现
 */
public class Demo6 {
    public static BlockingQueue<Integer> blockingQueue = new ArrayBlockingQueue<>(3);


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
                try {
                    int item = (int) (Math.random() * 100);
                    blockingQueue.put(item);

                    System.out.println("Produce: " + item);

                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }


    static class Consumer implements Runnable {

        @Override
        public void run() {

            while (true) {
                try {
                    Integer item = blockingQueue.take();

                    System.out.println("Consume: " + item);

                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

    }
}


