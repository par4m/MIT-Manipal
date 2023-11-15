public class ThreadOutputExample {

    public static void main(String[] args) {

        Thread thread1 = new Thread(new Runnable() {

            @Override

            public void run() {

                System.out.print("A ");

            }

        });

 

        Thread thread2 = new Thread(new Runnable() {

            @Override

            public void run() {

                System.out.print("B ");

            }

        });

 

        thread1.start();

        thread2.start();

    }

}

 