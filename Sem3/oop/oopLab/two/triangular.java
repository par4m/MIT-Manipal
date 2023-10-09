package two;

import java.util.Scanner;

public class triangular {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int[][] arr = new int[n][n];
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j <= i; j++) {
                arr[i][j] = i + j;
            }
        }
    }
}