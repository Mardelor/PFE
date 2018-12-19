import javassist.*;

import java.io.ByteArrayInputStream;
import java.lang.instrument.ClassFileTransformer;
import java.lang.instrument.IllegalClassFormatException;
import java.security.ProtectionDomain;

/**
 * Defines which class & methods will be transformed and how
 */
public class HadoopTransformer implements ClassFileTransformer {
    @Override
    public byte[] transform(ClassLoader loader, String className, Class classBeingRedefined, ProtectionDomain protectionDomain,
                            byte[] classfileBuffer) throws IllegalClassFormatException {
        byte[] byteCode = classfileBuffer;

        if (className.equals("MapClass") || className.equals("ReduceClass")) {
            System.out.println("Instrumenting......");
            try {
                ClassPool classPool = ClassPool.getDefault();
                // classPool.appendClassPath("/home/rem/.m2/repository/map-reduce-sample/hadoop-agent/1.0-SNAPSHOT/hadoop-agent-1.0-SNAPSHOT.jar");
                // Makes CtClass to be able to modify it with javassist
                CtClass ctClass = classPool.makeClass(new ByteArrayInputStream(classfileBuffer));
                // Create field which contains all methods to use !
                CtClass hadoopTrace = ClassPool.getDefault().get("ezTrace.HadoopTrace");
                CtField f = new CtField(hadoopTrace, "hTrace", ctClass);
                ctClass.addField(f);
                CtConstructor constructors[] = ctClass.getDeclaredConstructors();
                for (CtConstructor t : constructors) {
                    t.insertBeforeBody("hTrace = new HadoopTrace();");
                }
                System.out.println("Instrumenting methods...");

                CtMethod[] methods = ctClass.getDeclaredMethods();
                for (CtMethod method : methods) {
                    if (method.getName().equals("map")) {
                        method.insertBefore("hTrace.mapProlog();");
                        method.insertAfter("hTrace.mapEpilog();");
                    } else if (method.getName().equals("reduce")) {
                        method.insertBefore("hTrace.reduceProlog();");
                        method.insertAfter("hTrace.reduceEpilog();");
                    }
                }
                byteCode = ctClass.toBytecode();
                ctClass.detach();
                System.out.println("Instrumentation complete.");
            } catch (Throwable ex) {
                System.out.println("Exception: " + ex);
                ex.printStackTrace();
            }
        }
        return byteCode;
    }
}
