import javassist.ClassPool;
import javassist.CtClass;
import javassist.CtMethod;

import java.io.ByteArrayInputStream;
import java.lang.instrument.ClassFileTransformer;
import java.lang.instrument.IllegalClassFormatException;
import java.security.ProtectionDomain;

public class HelloWorldTransformer implements ClassFileTransformer {
    @Override
    public byte[] transform(ClassLoader classLoader, String s, Class<?> aClass,
                            ProtectionDomain protectionDomain, byte[] bytes) throws IllegalClassFormatException {
        byte[] newBytes = bytes;

        if (s.equals("HelloWorld")) {
            System.out.println("Instrumenting...");
            try {
                ClassPool classPol = ClassPool.getDefault();
                CtClass ctClass = classPol.makeClass(new ByteArrayInputStream(bytes));
                CtMethod[] methods = ctClass.getDeclaredMethods();
                for (CtMethod method : methods) {
                    method.addLocalVariable("startTime", CtClass.longType);
                    method.insertBefore("startTime = System.nanoTime();");
                    method.insertAfter("System.out.println(\"Execution Duration " + "(nano sec): \"+ ((System.nanoTime() - startTime)/1000000) + \" ms\");");
                }
                newBytes = ctClass.toBytecode();
                ctClass.detach();
                System.out.println("Instrumenting complete !");
            } catch (Throwable ex) {
                ex.printStackTrace();
            }
        }
        return newBytes;
    }
}
