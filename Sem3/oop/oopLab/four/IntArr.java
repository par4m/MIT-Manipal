package four;

public class IntArr {

    int arr[];

    IntArr(int arr1[]) {
        arr = new int[arr1.length];
        for (int i = 0; i < arr1.length; i++) {
            arr[i] = arr1[i];
        }
    }

    void compare(IntArr b) {
        if (this.arr == b.arr)
            System.out.println("equal");
    }

    public static void main(String[] args) {
        int[] arr1 = { 1, 2, 3, 4, 5 };
        IntArr a = new IntArr(arr1);
        IntArr b = new IntArr(arr1);
        a.compare(b);
    }
}
