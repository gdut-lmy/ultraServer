//
// Created by lmy on 2022/10/31.
//

#include "ultra/ultra.h"


static ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

static int timeout = 1000;
static ultra::Timer::ptr s_timer;

void timer_callback() {
    ULTRA_LOG_INFO(g_logger) << "timer callback, timeout = " << timeout;
    timeout += 1000;
    if(timeout < 5000) {
        s_timer->reset(timeout, true);
    } else {
        s_timer->cancel();
    }
}

void test_timer() {
    ultra::IOManager iom;

    // 循环定时器
    s_timer = iom.addTimer(1000, timer_callback, true);

    // 单次定时器
    iom.addTimer(500, []{
        ULTRA_LOG_INFO(g_logger) << "500ms timeout";
    });
    iom.addTimer(5000, []{
        ULTRA_LOG_INFO(g_logger) << "5000ms timeout";
    });
}

int main(int argc, char *argv[]) {
    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    test_timer();

    ULTRA_LOG_INFO(g_logger) << "end";

    return 0;
}
