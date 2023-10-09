package five.two;

import java.util.Scanner;

class Employee {
    String name;

    Employee(String name) {
        this.name = name;
    }

    void sortNames(Employee e[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (e[j].name.compareTo(e[j + 1].name) > 1) {
                    Employee temp = e[j];
                    e[j] = e[j + 1];
                    e[j + 1] = temp;
                }
            }
        }

    }

    void display() {
        System.out.println(this.name);
    }

}

public class EmployeeDemo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Employee[] e = new Employee[3];
        for (int i = 0; i < 3; i++) {
            System.out.println("Enter name for " + i);
            String n = sc.nextLine();
            e[i] = new Employee(n);
        }
        e[0].sortNames(e, 3);

        // print after sorting
        for (int i = 0; i < 3; i++) {
            System.out.println(e[i].name);
        }

    }
}
