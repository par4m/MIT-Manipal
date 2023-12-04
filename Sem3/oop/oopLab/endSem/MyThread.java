public class MyThread extends Thread {
    public void run() {
        for (int i = 10; i > 0; i--) {
            System.out.println("Thread #1: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        System.out.println("Thread #1 is Finished");
    }
}
