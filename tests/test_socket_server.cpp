//
// Created by lmy on 2022/11/8.
//

#include "ultra/ultra.h"

static ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

void test_tcp_server() {
    int ret;

    auto addr = ultra::Address::LookupAnyIPAddress("0.0.0.0:12345");
    ULTRA_ASSERT(addr);

    auto socket = ultra::Socket::CreateTCPSocket();
    ULTRA_ASSERT(socket);

    ret = socket->bind(addr);
    ULTRA_ASSERT(ret);

    ULTRA_LOG_INFO(g_logger) << "bind success";

    ret = socket->listen();
    ULTRA_ASSERT(ret);

    ULTRA_LOG_INFO(g_logger) << socket->toString() ;
    ULTRA_LOG_INFO(g_logger) << "listening...";

    while(1) {
        auto client = socket->accept();
        ULTRA_ASSERT(client);
        ULTRA_LOG_INFO(g_logger) << "new client: " << client->toString();
        client->send("hello world", strlen("hello world"));
        client->close();
    }
}

int main(int argc, char *argv[]) {
    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    ultra::IOManager iom(2);
    iom.schedule(&test_tcp_server);

    return 0;
}