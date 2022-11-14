//
// Created by lmy on 2022/11/8.
//

#include<ultra/ultra.h>

static ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

void test_tcp_client() {
    int ret;

    auto socket = ultra::Socket::CreateTCPSocket();
    ULTRA_ASSERT(socket);

    auto addr = ultra::Address::LookupAnyIPAddress("0.0.0.0:12345");
    ULTRA_ASSERT(addr);

    ret = socket->connect(addr);
    ULTRA_ASSERT(ret);

    ULTRA_LOG_INFO(g_logger) << "connect success, peer address: " << socket->getRemoteAddress()->toString();

    std::string buffer;
    buffer.resize(1024);
    socket->recv(&buffer[0], buffer.size());
    ULTRA_LOG_INFO(g_logger) << "recv: " << buffer;
    socket->close();

    return;
}

int main(int argc, char *argv[]) {
    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    ultra::IOManager iom;
    iom.schedule(&test_tcp_client);

    return 0;
}