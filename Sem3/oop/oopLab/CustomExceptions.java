
class MyException extends Exception {
    MyException(String message) {
        super(message);
    }

    MyException() {

    }

    MyException(Throwable cause) {
        super(cause);
    }

    MyException(String message, Throwable cause) {
        super(message, cause);
    }
}

public class CustomExceptions {

    public static void main(String[] args) throws MyException {
        validateAge(-1);
    }

    private static void validateAge(int age) throws MyException {
        if (age < 0) {
            throw new MyException("Message", new RuntimeException());
        }
    }
}

// extends RuntimeException => unchecked exception => dont need throws in
// functions
