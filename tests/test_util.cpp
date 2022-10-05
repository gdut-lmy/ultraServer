//
// Created by lmy on 2022/10/5.
//

#include "ultra/ultra.h"

ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

void test2() {
    std::cout << ultra::BacktraceToString() << std::endl;
}

void test1() {
    test2();
}

void test_backtrace() {
    test1();
}

int main() {
    ULTRA_LOG_INFO(g_logger) << ultra::GetCurrentMS();
    ULTRA_LOG_INFO(g_logger) << ultra::GetCurrentUS();
    ULTRA_LOG_INFO(g_logger) << ultra::ToUpper("hello");
    ULTRA_LOG_INFO(g_logger) << ultra::ToLower("HELLO");
    ULTRA_LOG_INFO(g_logger) << ultra::Time2Str();
    ULTRA_LOG_INFO(g_logger) << ultra::Str2Time("1970-01-01 00:00:00"); // -28800

    std::vector<std::string> files;
    ultra::FSUtil::ListAllFile(files, "../ultra", ".cpp");
    for (auto &i: files) {
        ULTRA_LOG_INFO(g_logger) << i;
    }

    // todo, more...

    test_backtrace();

    //ULTRA_ASSERT2(false, "assert");
    return 0;
}