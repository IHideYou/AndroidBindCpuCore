#include <jni.h>
#include <string>
#include "CpuSetting.h"

extern "C" JNIEXPORT jstring JNICALL
Java_cn_com_cpusetdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_cn_com_cpusetdemo_MainActivity_jniSetCPUCore(JNIEnv *env, jobject thiz, jint core1,
                                                  jint core2, jint core3, jint core4) {
    return SetCPUCore(core1, core2, core3, core4);
}
