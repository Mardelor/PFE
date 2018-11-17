package hellothread;

import java.util.ArrayList;

public class HelloThread implements Runnable {

    static {
        System.loadLibrary("hellothread");
    }

    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Usage : hellothread.jar [nThreads] [Time(sec)]");
            return;
        }
        int n = Integer.parseInt(args[0]);
        int t = Integer.parseInt(args[1]);
        ArrayList<Thread> threads = new ArrayList<>();

        for (int i=0; i<n; i++) {
            threads.add(new Thread(new HelloThread()));
            threads.get(i).start();
        }

        try {
            Thread.sleep(1000*t);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        for (Thread th : threads) {
            th.interrupt();
        }
        return;
    }

    private native void sayHello();

    @Override
    public void run() {
        try {
            while (!Thread.currentThread().isInterrupted()) {
                this.sayHello();
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
