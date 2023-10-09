import java.util.Scanner;

public class Vehicle {

    int n;
    int fuelNo;

    Vehicle() {

    }

    Vehicle(int a, int b) {
        this.n = a;
        this.fuelNo = b;
    }

    protected void finalize() {
        System.out.println("Object destroyed ");
    }

}

class VehicleDemo {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        Vehicle new1 = new Vehicle(a, b);
        Vehicle new2 = new Vehicle(4, 6);
        System.out.println(new1.n + " " + new1.fuelNo);
        new1 = new2;
        System.gc();

    }
}