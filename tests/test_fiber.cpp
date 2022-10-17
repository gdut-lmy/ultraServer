//
// Created by lmy on 2022/10/17.
//

#include "ultra/ultra.h"



ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

void run_in_fiber2() {
    ULTRA_LOG_INFO(g_logger) << "run_in_fiber2 begin";
    ULTRA_LOG_INFO(g_logger) << "run_in_fiber2 end";
}

void run_in_fiber() {
    ULTRA_LOG_INFO(g_logger) << "run_in_fiber begin";

    ULTRA_LOG_INFO(g_logger) << "before run_in_fiber yield";
    ultra::Fiber::GetThis()->yield();
    ULTRA_LOG_INFO(g_logger) << "after run_in_fiber yield";

    ULTRA_LOG_INFO(g_logger) << "run_in_fiber end";
    // fiber结束之后会自动返回主协程运行
}

void test_fiber() {
    ULTRA_LOG_INFO(g_logger) << "test_fiber begin";

    // 初始化线程主协程
    ultra::Fiber::GetThis();

    ultra::Fiber::ptr fiber(new ultra::Fiber(run_in_fiber, 0, false));
    ULTRA_LOG_INFO(g_logger) << "use_count:" << fiber.use_count(); // 1

    ULTRA_LOG_INFO(g_logger) << "before test_fiber resume";
    fiber->resume();
    ULTRA_LOG_INFO(g_logger) << "after test_fiber resume";

    /**
     * 关于fiber智能指针的引用计数为3的说明：
     * 一份在当前函数的fiber指针，一份在MainFunc的cur指针
     * 还有一份在在run_in_fiber的GetThis()结果的临时变量里
     */
    ULTRA_LOG_INFO(g_logger) << "use_count:" << fiber.use_count(); // 3

    ULTRA_LOG_INFO(g_logger) << "fiber status: " << fiber->getState(); // READY

    ULTRA_LOG_INFO(g_logger) << "before test_fiber resume again";
    fiber->resume();
    ULTRA_LOG_INFO(g_logger) << "after test_fiber resume again";

    ULTRA_LOG_INFO(g_logger) << "use_count:" << fiber.use_count(); // 1
    ULTRA_LOG_INFO(g_logger) << "fiber status: " << fiber->getState(); // TERM

    fiber->reset(run_in_fiber2); // 上一个协程结束之后，复用其栈空间再创建一个新协程
    fiber->resume();

    ULTRA_LOG_INFO(g_logger) << "use_count:" << fiber.use_count(); // 1
    ULTRA_LOG_INFO(g_logger) << "test_fiber end";
}

int main(int argc, char *argv[]) {
    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    ultra::SetThreadName("main_thread");
    ULTRA_LOG_INFO(g_logger) << "main begin";

    std::vector<ultra::Thread::ptr> thrs;
    for (int i = 0; i < 1; i++) {
        thrs.push_back(ultra::Thread::ptr(
                new ultra::Thread(&test_fiber, "thread_" + std::to_string(i))));
    }

    for (auto i : thrs) {
        i->join();
    }

    ULTRA_LOG_INFO(g_logger) << "main end";
    return 0;
}