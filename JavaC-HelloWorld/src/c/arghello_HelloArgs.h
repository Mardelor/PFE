/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class arghello_HelloArgs */

#ifndef _Included_arghello_HelloArgs
#define _Included_arghello_HelloArgs
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     arghello_HelloArgs
 * Method:    print
 * Signature: (SIJFDCZ)V
 */
JNIEXPORT void JNICALL Java_arghello_HelloArgs_print
  (JNIEnv *, jobject, jshort, jint, jlong, jfloat, jdouble, jchar, jboolean);

/*
 * Class:     arghello_HelloArgs
 * Method:    sayMyName
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_arghello_HelloArgs_sayMyName
  (JNIEnv *, jobject, jstring);

/*
 * Class:     arghello_HelloArgs
 * Method:    count
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_arghello_HelloArgs_count
  (JNIEnv *, jobject, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
