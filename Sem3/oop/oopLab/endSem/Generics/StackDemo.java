
package Generics;

import java.util.ArrayList;

class Stack<T> {
    public int max = 10;
    int top = -1;
    public ArrayList<T> arr1;

    public Stack(int max) {
        this.max = max;
        arr1 = new ArrayList<>();
    }

    public void push(T data) {
        if (top <= max) {
            top++;
            arr1.add(data);
        }
    }

    public T pop() {
        T x = arr1.get(top);
        arr1.remove(top);
        top--;
        return x;
    }

    public void display() {
        for (int i = 0; i <= top; i++) {
            if (arr1.get(i) instanceof Student) {
                ((Student) arr1.get(i)).display();
            } else {
                ((Employee) arr1.get(i)).display();
            }
        }
    }

}

class Student {
    private int roll;
    private String name;

    Student(int roll, String name) {
        this.roll = roll;
        this.name = name;
    }

    public void display() {
        System.out.println(this.roll);
        System.out.println(this.name);
    }

}

class Employee {
    private int id;
    private String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void display() {
        System.out.println(this.id);
        System.out.println(this.name);
    }

}

public class StackDemo {
    public static void main(String[] args) {
        Stack<Student> s = new Stack<>(10);
        s.push(new Student(1, "Param"));
        Stack<Employee> e = new Stack<>(10);
        e.push(new Employee(1, "Arav"));
        s.display();
        e.display();

    }
}
