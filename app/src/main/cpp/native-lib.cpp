#include <jni.h>
#include <string>

// 引入log头文件
#include <android/log.h>
// log标签
#define  TAG    "zwy"
// 定义info信息
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
// 定义debug信息
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
// 定义error信息
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)


extern "C"
JNIEXPORT jstring JNICALL
Java_com_vst_jnidemo_JniTest_sayHello(JNIEnv *env, jobject instance) {

    return env->NewStringUTF("Hello Jni!!!");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_vst_jnidemo_JniTest_join(JNIEnv *env, jobject instance, jstring str_) {
    //jstring转char *，c中的字符串为char *
    const char *str = env->GetStringUTFChars(str_, 0);
    std::string s = str;
    char *newStr = "this is jni!";
    s = s + newStr;
    LOGI(">>%s", str);
    //释放字符串
    env->ReleaseStringUTFChars(str_, str);
    return env->NewStringUTF(s.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_vst_jnidemo_JniTest_total__II(JNIEnv *env, jobject instance, jint a, jint b) {
    int rs = a + b;
    return rs;
}
extern "C"
JNIEXPORT jobject JNICALL
Java_com_vst_jnidemo_JniTest_tObj(JNIEnv *env, jobject instance, jobject userBean) {
    //获取对象的class
    jclass clazz = env->GetObjectClass(userBean);
    //获取对象中属性的get方法
    jmethodID idMethodID = env->GetMethodID(clazz, "getId", "()J");
    jmethodID nameMethodID = env->GetMethodID(clazz, "getName", "()Ljava/lang/String;");
    jmethodID ageMethodID = env->GetMethodID(clazz, "getAge", "()I");
    jmethodID isManMethodID = env->GetMethodID(clazz, "isMan", "()Z");
    //通过对象的get方法获取属性值
    jlong id = env->CallLongMethod(userBean, idMethodID);
    jstring name = (jstring) env->CallObjectMethod(userBean, nameMethodID, NULL);
    jint age = env->CallIntMethod(userBean, ageMethodID);
    jboolean isMan = env->CallBooleanMethod(userBean, isManMethodID);
    const char *n = env->GetStringUTFChars(name, 0);
    LOGI("id>>%d", id);
    LOGI("name>>>%s", n);
    LOGI("age>>>%d", age);
    LOGI("isMan>>>%d", isMan);

    //重新设置对象的属性值
    jfieldID ageFieldID = env->GetFieldID(clazz, "age", "I");
    env->SetIntField(userBean, ageFieldID, age + 2);
    //返回对象给java代码
    return userBean;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_vst_jnidemo_JniTest_getObj(JNIEnv *env, jobject instance) {
    //UserBean类的路径
    const char *path = "com/vst/jnidemo/UserBean";
    //发现UserBean类
    jclass clazz = env->FindClass(path);
    //为新的java类对象分配内存
    jobject userBean = env->AllocObject(clazz);
    //获取UserBean属性id
    jfieldID idFieldID = env->GetFieldID(clazz, "id", "J");
    jfieldID nameFieldID = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
    jfieldID ageFieldID = env->GetFieldID(clazz, "age", "I");
    jfieldID isManFieldID = env->GetFieldID(clazz, "isMan", "Z");

    env->SetLongField(userBean, idFieldID, 1006L);
    env->SetObjectField(userBean, nameFieldID, env->NewStringUTF("Jackkk"));
    env->SetIntField(userBean, ageFieldID, 66);
    env->SetBooleanField(userBean, isManFieldID, false);

    return userBean;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_vst_jnidemo_JniTest_tList(JNIEnv *env, jobject instance, jobject list) {
    //获取List对象的class
    jclass listClazz = env->GetObjectClass(list);
    //获取List对象的get和size方法
    jmethodID listGetMethodID = env->GetMethodID(listClazz, "get", "(I)Ljava/lang/Object;");
    jmethodID listSizeMethodID = env->GetMethodID(listClazz, "size", "()I");
    jint len = env->CallIntMethod(list, listSizeMethodID);
    for (int i = 0; i < len; i++) {
        jobject userBean = env->CallObjectMethod(list,listGetMethodID,i);
    }
}