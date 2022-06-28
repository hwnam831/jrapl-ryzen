/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class JRAPL */

#ifndef _Included_JRAPL
#define _Included_JRAPL
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     JRAPL
 * Method:    initRAPL
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_JRAPL_initRAPL
  (JNIEnv *, jclass);

/*
 * Class:     JRAPL
 * Method:    closeRAPL
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_JRAPL_closeRAPL
  (JNIEnv *, jclass);

/*
 * Class:     JRAPL
 * Method:    numCores
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_JRAPL_numCores
  (JNIEnv *, jclass);

/*
 * Class:     JRAPL
 * Method:    readCoreEnergy
 * Signature: (I)D
 */
JNIEXPORT jdouble JNICALL Java_JRAPL_readCoreEnergy
  (JNIEnv *, jclass, jint);

/*
 * Class:     JRAPL
 * Method:    readPackageEnergy
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_JRAPL_readPackageEnergy
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
