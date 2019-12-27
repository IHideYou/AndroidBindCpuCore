//
// Created by admin on 2019/12/26.
//
#ifndef CPUSETDEMO_CPUSETTING_H
#define CPUSETDEMO_CPUSETTING_H
#include <unistd.h>
#include <android/log.h>
#define  LOG_TAG    "test"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


static int getCores() {
    return sysconf(_SC_NPROCESSORS_CONF);
}

int SetCPUCore(int core1, int core2 = -1, int core3 = -1, int core4 = -1);


#endif //CPUSETDEMO_CPUSETTING_H
