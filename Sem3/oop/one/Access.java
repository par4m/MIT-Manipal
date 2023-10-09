package one;

public abstract class Access {
    int a;

    int x() {
        System.out.println(a);
        return a;
    }

    Access() {

    }

    abstract void setX(int x);

}

class AccessDemo extends Access {

    void displaY() {

    }

    void setX(int x) {

    }

    public static void main(String[] args) {
    }
}
