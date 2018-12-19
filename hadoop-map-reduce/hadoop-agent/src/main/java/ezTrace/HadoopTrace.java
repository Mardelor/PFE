package ezTrace;

/**
 * Defines functions to call and implement with ezTrace
 */
public class HadoopTrace {
    /**
     * Map
     */
    public native void mapProlog();
    public native void mapEpilog();

    /**
     * Reduce
     */
    public native void reduceProlog();
    public native void reduceEpilog();

    /**
     * Load native library
     */
    static {
        System.loadLibrary("hadooptrace");
    }
}
