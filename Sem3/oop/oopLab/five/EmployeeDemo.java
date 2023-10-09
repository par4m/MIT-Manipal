package five;

class Employee {
    String name;

    Employee(String name) {
        this.name = name;
    }

    public void formatEmployeeName() {
        // capitalize first letter of each word
        String[] arr = name.split(" "); // {param arora}
        String result = "";
        for (String x : arr) { // substring(0, end - 1)
            // x = arora
            // x.substring(0,1) => a .toUpperCase =? A => x.substring(1) =? rora =>
            String capitilized = x.substring(0, 1).toUpperCase() + x.substring(1).toLowerCase();
            // Param
            result += capitilized + " ";
        }
        this.name = result;
    }

    public void generateEmail() {
        String[] arr = name.split(" ");
        String email = "";
        // P => p + arr[1] // Arora => arora +
        email += arr[0].substring(0, 1).toLowerCase() + arr[1].substring(0).toLowerCase() + "@example.com";
        System.out.println(email); // parora@example.com
    }

    void extractInitials() {
        String[] arr = name.split(" ");
        System.out.println(arr[0].substring(0, 1) + arr[1].substring(0, 1));
    }

    void removeWhitespace() {
        String result = "";
        String[] arr = name.split(" ");
        result += arr[0] + arr[1];
        System.out.println(result);

    } // Param Arora ramArorPaa

    void containsSubstring(String sub) {
        if (name.contains(sub)) {
            System.out.println("Yes it contains " + sub);
        } else {
            System.out.println("does not contain");
        }
    }

    void display() {
        System.out.println(this.name);
    }
}

public class EmployeeDemo {

    public static void main(String[] args) {
        Employee e1 = new Employee("param arora");
        // Param Arora
        e1.formatEmployeeName();
        e1.display();
        e1.generateEmail();
        e1.extractInitials();
        e1.removeWhitespace();
        e1.containsSubstring("Param");

    }
}
