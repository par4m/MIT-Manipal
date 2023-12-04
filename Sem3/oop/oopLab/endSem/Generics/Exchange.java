package Generics;

public class Exchange {
    public static <T> void exchange(T[] arr, int index1, int index2) {
        T x = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = x;
    }

    public static void main(String[] args) {

        Integer[] arr = { 1, 2, 3, 4, 5, 6 };
        exchange(arr, 1, 2);
        System.out.println(arr[1] + " " + arr[2]);
    }
}
