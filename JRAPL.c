#include "JRAPL.h"
#include "ryzen.h"

JNIEXPORT void JNICALL Java_JRAPL_initRAPL
  (JNIEnv * env, jobject obj){
    init_rapl();
  }


JNIEXPORT void JNICALL Java_JRAPL_closeRAPL
  (JNIEnv * env, jobject obj){
    close_rapl();
  }


JNIEXPORT jint JNICALL Java_JRAPL_numCores
  (JNIEnv * env, jobject obj){
    return total_cores/2;
  }


JNIEXPORT jdouble JNICALL Java_JRAPL_readCoreEnergy
  (JNIEnv * env, jobject obj, jint core){
    return read_core_energy(core);
  }


JNIEXPORT jdouble JNICALL Java_JRAPL_readPackageEnergy
  (JNIEnv * env, jobject obj){
    return read_package_energy();
  }