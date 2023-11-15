class MyThread extends Thread {

    public void run() {

        System.out.println("Running");

    }

}

public class ThreadTest {

    public static void main(String args[]) throws InterruptedException {

        Runnable r = new MyThread(); // L1

        Thread myThread = new Thread(r); // L2

        myThread.start();

    }

}