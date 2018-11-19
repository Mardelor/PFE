#include <jni.h>
#include <stdio.h>
#include "arghello_HelloArgs.h"

JNIEXPORT void JNICALL
Java_arghello_HelloArgs_print (JNIEnv *env, jobject obj, jshort sh, jint i, jlong l, jfloat f, jdouble d, jchar c, jboolean b) {
    printf("Ok ! short : %d, int : %d, long : %d, float : %f, double : %f, char : %u, boolean : %u\n", sh, i, l, f, d, c, b);
    return;
}

JNIEXPORT void JNICALL
Java_arghello_HelloArgs_sayMyName (JNIEnv *env, jobject obj, jstring string) {
    const char* c = (*env)->GetStringUTFChars(env, string, NULL);
    printf("Ok ! %s\n", c);
    return;
}

JNIEXPORT jint JNICALL
Java_arghello_HelloArgs_count(JNIEnv *env, jobject obj, jint a, jint b) {
    return (jint) (a + b);
}
