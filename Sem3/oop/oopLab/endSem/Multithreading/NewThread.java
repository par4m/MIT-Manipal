package Multithreading;

public class NewThread extends Thread {
    public void run() {
        System.out.println("Param");
    }

    public static void main(String[] args) throws InterruptedException {
        NewThread n1 = new NewThread();
        n1.start();
        n1.sleep(5000);
        n1.start();
    }
}
