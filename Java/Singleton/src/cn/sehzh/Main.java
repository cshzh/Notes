package cn.sehzh;

public class Main {

    public static void main(String[] args) {
        Demo3 instance = Demo3.getInstance();
        Demo3 instance1 = Demo3.getInstance();
        System.out.println(instance == instance1);
    }
}
