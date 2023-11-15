class Gen<V extends T, T> {

    T t;

    V v;

    Gen(V a, T b) {

        v = b;

        t = a;

    }

}

class GenDemo {

    public static void main(String[] args) {

        Gen<Number, Number> g = new Gen<Number, Number>(10, 10);

        System.out.print(g.v.doubleValue());

    }

}