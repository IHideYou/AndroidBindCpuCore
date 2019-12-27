//
// Created by admin on 2019/12/26.
//
#include <locale.h>
#include <sched.h>

#include "CpuSetting.h"
/**
 * 设置当前线程运行在哪几个CPU核心
 * @param core1 核心index，0开始
 * @param core2 核心index，0开始
 * @param core3 核心index，0开始
 * @param core4 核心index，0开始
 * @return -5参数超过max（核心数-1），-1失败，1成功
 */
int SetCPUCore(int core1, int core2, int core3, int core4) {
//    return 1;
    int ret = 0;
    int cores = getCores();
//    LOGI("get cpu number = %d\n", cores);
    if (core1 >= cores || core2 >= cores || core3 >= cores || core4 >= cores) {
        ret = -5;
        LOGI("your set cpu is beyond the cores,exit...");
    } else {
        cpu_set_t mask;
        CPU_ZERO(&mask);
        CPU_SET(core1, &mask);
        if (core2 != -1) {
            CPU_SET(core2, &mask);
        }
        if (core3 != -1) {
            CPU_SET(core3, &mask);
        }
        if (core4 != -1) {
            CPU_SET(core4, &mask);
        }
        pid_t pid = gettid();
        //int err;
        ret = sched_setaffinity(pid, sizeof(cpu_set_t), &mask);
        if (ret == -1) {
            //perror("sched_setaffinity");
            //exit(EXIT_FAILURE);
            //err = errno;
            LOGI("Error in the syscall: thread %d setaffinity: mask = %d, err=%d", pid, mask,
                 ret);
        } else {
//            LOGI("set %d affinity to %d,%d,%d,%d success", pid, core1, core2, core3, core4);
        }
    }
    return ret;
}