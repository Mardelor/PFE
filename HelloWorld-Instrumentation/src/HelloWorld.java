public class HelloWorld {

    public static void main(String[] args) {
        System.out.println("Hello...");
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("...World!");
    }
}
