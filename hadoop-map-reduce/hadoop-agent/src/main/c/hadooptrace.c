#include <jni.h>
#include <stdio.h>
#include <pthread.h>
#include "eztrace.h"
#include "hadooptrace_ev_codes.h"
#include "ezTrace_HadoopTrace.h"

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_mapProlog(JNIEnv* env, jobject obj) {
    printf("map from thread %lu ...\n", pthread_self());
    EZTRACE_EVENT1(EZTRACE_HADOOP_MAP_PROLOG, pthread_self());
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_mapEpilog(JNIEnv* env, jobject obj) {
    printf("map ok\n");
    EZTRACE_EVENT1(EZTRACE_HADOOP_MAP_EPILOG, pthread_self());
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_reduceProlog(JNIEnv* env, jobject obj) {
    printf("reduce from thread %lu ...\n", pthread_self());
    EZTRACE_EVENT1(EZTRACE_HADOOP_REDUCE_PROLOG, pthread_self());
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_reduceEpilog(JNIEnv* env, jobject obj) {
    printf("reduce ok\n");
    EZTRACE_EVENT1(EZTRACE_HADOOP_REDUCE_EPILOG, pthread_self());
}
