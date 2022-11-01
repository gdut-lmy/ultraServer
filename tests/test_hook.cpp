//
// Created by lmy on 2022/11/1.
//

#include "ultra/ultra.h"


ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();


void test_sleep() {

    ULTRA_LOG_INFO(g_logger) << "test sleep begin;";

    ultra::IOManager iom;
    iom.schedule([] {
        sleep(2);
        ULTRA_LOG_INFO(g_logger) << "sleep 2s";
    });

    iom.schedule([] {
        sleep(3);
        ULTRA_LOG_INFO(g_logger) << " sleep 3s";
    });

    ULTRA_LOG_INFO(g_logger) << "test sleep end;";

}


int main(int argc, char *argv[]) {

    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    test_sleep();

    ULTRA_LOG_INFO(g_logger) << "main end";

    return 0;

}