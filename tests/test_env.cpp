//
// Created by lmy on 2022/10/8.
//

#include "ultra/ultra.h"

ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

ultra::Env *g_env = ultra::EnvMgr::GetInstance();

int main(int argc, char *argv[]) {
    g_env->addHelp("h", "print this help message");

    bool is_print_help = false;
    if(!g_env->init(argc, argv)) {
        is_print_help = true;
    }
    if(g_env->has("h")) {
        is_print_help = true;
    }

    if(is_print_help) {
        g_env->printHelp();
        return false;
    }

    ULTRA_LOG_INFO(g_logger)<< "exe: " << g_env->getExe();
    ULTRA_LOG_INFO(g_logger) <<"cwd: " << g_env->getCwd();
    ULTRA_LOG_INFO(g_logger) << "absoluth path of test: " << g_env->getAbsolutePath("test");
    ULTRA_LOG_INFO(g_logger) << "conf path:" << g_env->getConfigPath();

    g_env->add("key1", "value1");
    ULTRA_LOG_INFO(g_logger) << "key1: " << g_env->get("key1");

    g_env->setEnv("key2", "value2");
    ULTRA_LOG_INFO(g_logger) << "key2: " << g_env->getEnv("key2");

    ULTRA_LOG_INFO(g_logger) << g_env->getEnv("PATH");

    return 0;
}