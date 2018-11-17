package hello;

/**
 * Little Wrapper which call C hello.HelloWorld
 */
public class HelloWorld {
    private native void sayHello();
    public static void main(String[] args) {
        new HelloWorld().sayHello();
    }
    static {
        System.loadLibrary("helloworld");
    }
}
