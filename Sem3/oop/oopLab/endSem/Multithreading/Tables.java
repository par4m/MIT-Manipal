package Multithreading;

public class Tables {

    public static void main(String[] args) {
        MultiplicationTable m1 = new MultiplicationTable(5);
        MultiplicationTable m2 = new MultiplicationTable(7);
        m1.start();
        m2.start();
    }

}
