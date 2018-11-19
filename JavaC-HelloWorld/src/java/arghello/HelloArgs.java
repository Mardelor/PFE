package arghello;

public class HelloArgs {
    static {
        System.loadLibrary("helloargs");
    }

    private native void print(short s, int i, long l, float f, double d, char c, boolean b);

    private native void sayMyName(String name);

    private native int count(int a, int b);

    public static void main(String[] args) {
        HelloArgs helloArgs = new HelloArgs();
        helloArgs.print((short) 2, 4, 8, (float) 4.0, 8.0, '1', true);
        helloArgs.sayMyName("Heisenberg");
        System.out.println("1426 + 5122 = " + helloArgs.count(1426, 5122));
    }
}
