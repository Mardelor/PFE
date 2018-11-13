import java.lang.instrument.Instrumentation;

public class HelloWorldAgent {
    public static void premain(String agentArgs, Instrumentation inst) {
        System.out.println("Executing premain...");
        inst.addTransformer(new HelloWorldTransformer());
    }
}
