package four;

import java.util.*;

public class Customer {
    private int id, number;
    private String name;
    private long limit;

    Customer(int id, int number,
            String name,
            long limit) {
        this.id = id;
        this.number = number;
        this.name = name;
        this.limit = limit;

    }

    public void display() {
        System.out.println(this.id + " " + this.number + " " + this.name + " " + this.limit);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Customer c[] = new Customer[5];

        for (int i = 0; i < 5; i++) {
            System.out.println("Enter for Obj " + i + 1);
            int id;
            int number;
            String name;
            long limit;
            id = sc.nextInt();
            number = sc.nextInt();
            name = sc.nextLine();
            limit = sc.nextLong();
            c[i] = new Customer(id, number, name, limit);

        }

        for (int j = 0; j < 5; j++) {
            c[j].display();
        }
    }
}
