class A<T> {

    <V extends T> void print(V x) {

        System.out.println("------------");

    }

}

class ADemo {

    public static void main(String[] args) {

        A<Number> ai = new A<Number>();

        ai.print(10);

    }

}