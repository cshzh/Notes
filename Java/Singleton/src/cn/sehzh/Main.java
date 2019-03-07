package cn.sehzh;

public class Main {

    public static void main(String[] args) {
        Demo5 instance = Demo5.INSTANCE;
        Demo5 instance1 = Demo5.INSTANCE;
        System.out.println(instance == instance1);
    }
}
