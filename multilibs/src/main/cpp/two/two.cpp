#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_vst_jnidemo_JniTest_sayHello(JNIEnv *env, jobject instance) {

    return env->NewStringUTF("Hello Jni!!!");
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_vst_multilibs_JniTest_getStr2(JNIEnv *env, jclass type) {

    // TODO


    return env->NewStringUTF("Hello,this is two...");
}