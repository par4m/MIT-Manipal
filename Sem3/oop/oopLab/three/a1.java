package three;

import java.util.*;

class ISBN {
    Scanner sc = new Scanner(System.in);
    long num;

    public void setNum() {
        num = sc.nextLong();
    }

    public void checkISBN() {
        int ctr = 0;
        long temp = this.num;
        while (temp != 0) {
            ctr++;
            temp = temp / 10;
        }
        if (ctr > 10 || ctr < 10) {
            System.out.println("ISBN Should be a 10 digit number");
        } else {
            long temp2 = this.num;
            int n = 10;
            long sum = 0;
            while (temp2 != 0) {
                long rem = n * (temp2 % 10);
                sum += rem;
                temp2 = temp2 / 10;
                n--;
            }
            if (sum % 11 == 0) {
                System.out.println("Correct ISBN");
            }
        }

    }

}

public class a1 {
    public static void main(String[] args) {
        ISBN c = new ISBN();
        c.setNum();
        c.checkISBN();

    }
}
