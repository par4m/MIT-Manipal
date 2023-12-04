package Generics;

public class MyGenericClass<T> {
    T val;

    MyGenericClass(T val) {
        this.val = val;
    }

    public T getValue() {
        return val;
    }

}
