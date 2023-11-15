
public class ExceptionDemo {
    public static void main(String[] args) {
        try {
            getInt();
        } catch (ArithmeticException | NullPointerException e) {
            System.out.println(e);
        }
    }

    public static void getInt() {
        int myint = Integer.parseInt("aaa");
    }

}

// extends RuntimeException => unchecked exception => dont need throws in
// functions