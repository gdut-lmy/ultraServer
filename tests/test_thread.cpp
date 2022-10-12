//
// Created by lmy on 2022/10/10.
//

#include "ultra/ultra.h"

ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

int count = 0;
ultra::Mutex s_mutex;

void func1(void *arg) {
    ULTRA_LOG_INFO(g_logger) << "name:" << ultra::Thread::GetName()
                             << " this.name:" << ultra::Thread::GetThis()->getName()
                             << " thread name:" << ultra::GetThreadName()
                             << " id:" << ultra::GetThreadId()
                             << " this.id:" << ultra::Thread::GetThis()->getId();
    ULTRA_LOG_INFO(g_logger) << "arg: " << *(int *) arg;
    for (int i = 0; i < 10000; i++) {
        ultra::Mutex::Lock lock(s_mutex);
        ++count;
    }
}

int main(int argc, char *argv[]) {
    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    std::vector<ultra::Thread::ptr> thrs;
    int arg = 123456;
    for (int i = 0; i < 3; i++) {
        // 带参数的线程用std::bind进行参数绑定
        ultra::Thread::ptr thr(new ultra::Thread(std::bind(func1, &arg), "thread_" + std::to_string(i)));
        thrs.push_back(thr);
    }

    for (int i = 0; i < 3; i++) {
        thrs[i]->join();
    }

    ULTRA_LOG_INFO(g_logger) << "count = " << count;
    return 0;
}

