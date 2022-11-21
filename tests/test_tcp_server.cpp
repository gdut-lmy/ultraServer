//
// Created by lmy on 2022/11/21.
//

#include "ultra/ultra.h"



static ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();

/**
 * @brief 自定义TcpServer类，重载handleClient方法
 */
class MyTcpServer : public ultra::TcpServer {
protected:
    virtual void handleClient(ultra::Socket::ptr client) override;
};

void MyTcpServer::handleClient(ultra::Socket::ptr client) {
    ULTRA_LOG_INFO(g_logger) << "new client: " << client->toString();
    static std::string buf;
    buf.resize(4096);
    client->recv(&buf[0], buf.length()); // 这里有读超时，由tcp_server.read_timeout配置项进行配置，默认120秒
    ULTRA_LOG_INFO(g_logger) << "recv: " << buf;
    client->close();
}

void run() {
    ultra::TcpServer::ptr server(new MyTcpServer); // 内部依赖shared_from_this()，所以必须以智能指针形式创建对象
    auto addr = ultra::Address::LookupAny("0.0.0.0:12345");
    ULTRA_ASSERT(addr);
    std::vector<ultra::Address::ptr> addrs;
    addrs.push_back(addr);

    std::vector<ultra::Address::ptr> fails;
    while(!server->bind(addrs, fails)) {
        sleep(2);
    }

    ULTRA_LOG_INFO(g_logger) << "bind success, " << server->toString();

    server->start();
}

int main(int argc, char *argv[]) {
    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    ultra::IOManager iom(2);
    iom.schedule(&run);

    return 0;
}