//
// Created by lmy on 2022/10/8.
//

#include "ultra/ultra.h"

ultra::Logger::ptr g_logger = ULTRA_LOG_NAME("root");

ultra::ConfigVar<int>::ptr g_int = ultra::Config::Lookup("global.int", (int) 8080, "global int");
ultra::ConfigVar<float>::ptr g_float = ultra::Config::Lookup("global.float", (float) 10.2f, "global float");


void test_config() {

    ULTRA_LOG_INFO(g_logger) << "g_int: " << g_int->getValue();
    ULTRA_LOG_INFO(g_logger) << "g_float: " << g_float->getValue();

}


int main(int argc, char *argv[]) {

    //ULTRA_LOG_INFO(g_logger) << g_int->getValue();

    g_int->addListener([](const int &ov, const int &nv) {
        ULTRA_LOG_INFO(g_logger)<<"g_int value changed, the old value is: "<<ov <<", the new value is : "<<nv;
    });


    test_config();

    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir("conf");

    test_config();

    return 0;
}