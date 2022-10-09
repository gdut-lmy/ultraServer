//
// Created by lmy on 2022/9/28.
//

#include "ultra/ultra.h"

/**
 * @file test_log.cpp
 * @brief 日志类测试
 * @version 0.1
 * @date 2021-06-10
 */



#include <unistd.h>

ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT(); // 默认INFO级别

int main(int argc, char *argv[]) {

    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    ULTRA_LOG_FATAL(g_logger) << "fatal msg";
    ULTRA_LOG_ERROR(g_logger) << "err msg";
    ULTRA_LOG_INFO(g_logger) << "info msg";
    ULTRA_LOG_DEBUG(g_logger) << "debug msg";

    ULTRA_LOG_FMT_FATAL(g_logger, "fatal %s:%d", __FILE__, __LINE__);
    ULTRA_LOG_FMT_ERROR(g_logger, "err %s:%d", __FILE__, __LINE__);
    ULTRA_LOG_FMT_INFO(g_logger, "info %s:%d", __FILE__, __LINE__);
    ULTRA_LOG_FMT_DEBUG(g_logger, "debug %s:%d", __FILE__, __LINE__);

    sleep(1);
    ultra::SetThreadName("brand_new_thread");

    g_logger->setLevel(ultra::LogLevel::WARN);
    ULTRA_LOG_FATAL(g_logger) << "fatal msg";
    ULTRA_LOG_ERROR(g_logger) << "err msg";
    ULTRA_LOG_INFO(g_logger) << "info msg"; // 不打印
    ULTRA_LOG_DEBUG(g_logger) << "debug msg"; // 不打印


    ultra::FileLogAppender::ptr fileAppender(new ultra::FileLogAppender("./log.txt"));
    g_logger->addAppender(fileAppender);
    ULTRA_LOG_FATAL(g_logger) << "fatal msg";
    ULTRA_LOG_ERROR(g_logger) << "err msg";
    ULTRA_LOG_INFO(g_logger) << "info msg"; // 不打印
    ULTRA_LOG_DEBUG(g_logger) << "debug msg"; // 不打印

    ultra::Logger::ptr test_logger = ULTRA_LOG_NAME("test_logger");
    ultra::StdoutLogAppender::ptr appender(new ultra::StdoutLogAppender);
    ultra::LogFormatter::ptr formatter(
            new ultra::LogFormatter("%d:%rms%T%p%T%c%T%f:%l %m%n")); // 时间：启动毫秒数 级别 日志名称 文件名：行号 消息 换行
    appender->setFormatter(formatter);
    test_logger->addAppender(appender);
    test_logger->setLevel(ultra::LogLevel::WARN);

    ULTRA_LOG_ERROR(test_logger) << "err msg";
    ULTRA_LOG_INFO(test_logger) << "info msg"; // 不打印

    g_logger->setLevel(ultra::LogLevel::INFO);
    ULTRA_LOG_INFO(g_logger) << "logger config:" << ultra::LoggerMgr::GetInstance()->toYamlString();

    return 0;
}