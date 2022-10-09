//
// Created by lmy on 2022/10/8.
//

#include "ultra/ultra.h"

ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

ultra::ConfigVar<int>::ptr g_int = ultra::Config::Lookup("global.int", (int) 8080, "global int");
ultra::ConfigVar<float>::ptr g_float = ultra::Config::Lookup("global.float", (float) 10.2f, "global float");


int main(int argc, char *argv[]) {

    ULTRA_LOG_INFO(g_logger) << g_int->getValue();

    return 0;
}