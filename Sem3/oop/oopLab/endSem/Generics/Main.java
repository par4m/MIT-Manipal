package Generics;

public class Main {
    public static <T> void displayArray(T[] array) {
        for (T x : array) {
            System.out.println(x);
        }

    }

    public static <T> T getFirst(T[] arr) {
        return arr[0];

    }

    public static void main(String[] args) {
        Integer[] intArr = { 1, 2, 3, 4, 5 };
        displayArray(intArr);

        MyGenericClass<Integer> myInt = new MyGenericClass<>(1);
        System.out.println(myInt.getValue());
    }
}
