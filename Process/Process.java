class Process {
    private native void calculate();

    private int add(int n1, int n2) {
        return n1 + n2;
    }

    private int multiple(int n1, int n2) {
        return n1 * n2;
    }

    static {
        System.loadLibrary("CProcess");
    }

    public static void main(String args[]) {
        Process p = new Process();
        p.calculate();
    }
}
