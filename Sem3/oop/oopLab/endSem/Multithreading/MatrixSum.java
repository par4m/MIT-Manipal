package Multithreading;

class Matrix implements Runnable {
    private int arr[];

    Matrix(int arr[]) {
        this.arr = arr;
    }

    public void run() {

        int rowSum = 0;
        for (int x : arr) {
            rowSum += x;
        }

        System.out.println("Sum is : " + rowSum);

    }

}

public class MatrixSum {
    public static void main(String[] args) {
        int matrix[][] = {
                { 1, 2 }, { 3, 4 }, { 5, 6 },
                { 7, 8 }, { 9, 10 },
                { 11, 12 }, { 13, 14 }, { 15, 16 } };

        for (int arr[] : matrix) {
            Thread thread = new Thread(new Matrix(arr));
            thread.start();
        }

    }
}
