#include <jni.h>
#include <stdio.h>
#include <pthread.h>
#include "eztrace.h"
#include "hadooptrace_ev_codes.h"
#include "ezTrace_HadoopTrace.h"

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_mapProlog(JNIEnv* env, jobject obj) {
    printf("map from thread %d ...\n", pthread_self());
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_mapEpilog(JNIEnv* env, jobject obj) {
    printf("map ok\n");
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_reduceProlog(JNIEnv* env, jobject obj) {
    printf("reduce from thread %d ...\n", pthread_self());
}

JNIEXPORT void JNICALL Java_ezTrace_HadoopTrace_reduceEpilog(JNIEnv* env, jobject obj) {
    printf("reduce ok\n");
}
