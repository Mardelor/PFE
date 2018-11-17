#include <jni.h>
#include <stdio.h>
#include <pthread.h>
#include "hellothread_HelloThread.h"

JNIEXPORT void JNICALL
Java_hellothread_HelloThread_sayHello (JNIEnv* env, jobject obj) {
    printf("hello from thread %d\n", pthread_self());
    return;
}