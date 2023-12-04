package exceptionHandling;

class PushException extends Exception {
    PushException() {
        System.out.println("Cannot Push, Stack Full");
    }
}

class PopException extends Exception {
    PopException() {
        System.out.println("Cannot Pop Stack Empty ");
    }
}

public class Stack {
    int max;
    int arr[];
    int top = -1;

    Stack(int max) {
        this.max = max;
        arr = new int[max];
    }

    public void Push(int n) throws PushException {
        if (top <= max - 1) {
            throw new PushException();
        } else {
            top++;
            arr[top] = n;
        }
    }

    public int Pop() throws PopException {
        if (top == -1) {
            throw new PopException();
        } else {
            int x = arr[top];
            top--;
            return x;
        }
    }

    public static void main(String[] args) throws PopException {
        Stack s = new Stack(10);
        try {
            s.Push(1);
            s.Push(2);
            s.Push(3);
            s.Push(2);
            s.Push(2);
            s.Push(2);
            s.Push(2);
            s.Push(2);
            s.Push(2);
            s.Push(2);
            s.Push(2);
            s.Push(2);
            s.Push(2);

        } catch (Exception e) {
            System.out.println(e);
            System.out.println(e.getStackTrace());
        }

    }
}
