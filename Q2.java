public class Q2 {
    public native void sayHello(String pp, int m);

    static {
        System.loadLibrary("Q2C");
    }

    public static void main (String[] args) {
        Q2 h = new Q2();
        h.sayHello(args[0], Integer.parseInt(args[1]));
    }
}
