import java.util.Scanner;

public class Swapper {

    int x, y;

    Swapper(int x, int y) {
        this.x = x;
        this.y = y;
    }

}

class SwapperDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int a = sc.nextInt();
        // int b = sc.nextInt();
        // Swapper s1 = new Swapper(a, b);
        // System.out.println(s1.x + " " + s1.y);
        // int n = 5;
        // int arr[] = { 3, 4, 5, 6, 7 };
        // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < n - i - 1; j++) {
        // if (arr[j] > arr[j] + 1) {
        // int temp = arr[j];
        // arr[j] = arr[j + 1];
        // arr[j + 1] = temp;
        // }
        // }
        // }
        // for (int i = 0; i < n; i++) {
        // System.out.println(arr[i]);
        // }
        // int[][][] arr = new int[2][3][6];
        // System.out.println(arr[0].length);
        // int arr[] = {1,2,3,4,5};
        // int total = 0;
        // for(int i: arr) {
        // total+=i;
        // }
        // System.out.println(total);
        String s1 = "param arora";
        String s3 = "aaaaa";
        if (s1.equals(s3)) {
            System.out.println("same string");
        }
        // System.out.println(s1.length());
        // System.out.println(s1.charAt(5));
        // System.out.println(s1.compareTo(s3));
        // System.out.println(s1.indexOf(s3, 1));
        // System.out.println(s1.substring(1, 5));
        String[] s = s1.split(" ");

        for (String x : s) {
            System.out.println(x);
        }

        String result = "";
        for (String x : s) {
            String capitilisedFirst = x.substring(0, 1).toUpperCase() + x.substring(1);
            result += capitilisedFirst + " ";
        }

        // System.out.println(x);
        System.out.println(result);
        int total = 0;
        for (int i = 0; i < args.length; i++) {
            total += Integer.parseInt(args[i]);
        }
        System.out.println(total);
    }

}