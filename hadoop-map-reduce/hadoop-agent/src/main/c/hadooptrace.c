#include <jni.h>
#include <stdio.h>
#include <pthread.h>
#include "eztrace.h"
#include "hadooptrace_ev_codes.h"
#include "ezTrace_HadoopTrace.h"

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_mapProlog(JNIEnv* env, jobject obj) {
    EZTRACE_EVENT0(EZTRACE_HADOOP_MAP_PROLOG);
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_mapEpilog(JNIEnv* env, jobject obj) {
    EZTRACE_EVENT0(EZTRACE_HADOOP_MAP_EPILOG);
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_reduceProlog(JNIEnv* env, jobject obj) {
    EZTRACE_EVENT0(EZTRACE_HADOOP_REDUCE_PROLOG);
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_reduceEpilog(JNIEnv* env, jobject obj) {
    EZTRACE_EVENT0(EZTRACE_HADOOP_REDUCE_EPILOG);
}

void __hadooptrace_init(void) __attribute__ ((constructor));
/* Initialize the current library */
void __hadooptrace_init(void) {

    /* start event recording */
#ifdef EZTRACE_AUTOSTART
    eztrace_start ();
#endif
}

void __example_conclude(void) __attribute__ ((destructor));
void __example_conclude(void) {
    /* stop event recording */
    eztrace_stop();
}
