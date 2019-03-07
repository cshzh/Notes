package cn.sehzh;

import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Main {
    //    private static CountDownLatch latch = new CountDownLatch(50000);
    private static Lock lock = new ReentrantLock();

    private static int i = 0;
//    private static AtomicInteger i = new AtomicInteger();

    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(5);
        ExecutorService threadPoolExecutor = new ThreadPoolExecutor(5, 5, 0L,
                TimeUnit.MILLISECONDS, new LinkedBlockingDeque<>(16), new ThreadPoolExecutor.DiscardPolicy()
        );

        for (int j = 0; j < 50000; j++) {
            threadPoolExecutor.execute(() -> i++);
        }

        try {
            threadPoolExecutor.shutdown();


            threadPoolExecutor.awaitTermination(Long.MAX_VALUE, TimeUnit.MILLISECONDS);

            System.out.println(i);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
