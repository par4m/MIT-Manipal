class Gen<T> {

    T ob;

    Gen(T o) {

        ob = o;

    }

}

class GWCDemo {

    <T>
    static void method(Gen<T extends A> g){

System.out.println("Invoked correctly...");

}

    public static void main(String[] args) {

        Gen<A> ga = new Gen<A>(a);

        Gen<B> gb = new Gen<B>(b);

        Gen<C> gc = new Gen<C>(c);

        Gen<D> gd = new Gen<D>(d);

        method(gb);

        method(gc);

        method(gd);

        method(ga);

    }

}
