//
// Created by lmy on 2022/11/1.
//

#include "ultra/ultra.h"
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>


ultra::Logger::ptr g_logger = ULTRA_LOG_ROOT();


void test_sleep() {

    ULTRA_LOG_INFO(g_logger) << "test sleep begin;";

    ultra::IOManager iom;
    ultra::IOManager::GetThis();
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

void test_sock() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    inet_pton(AF_INET, "36.152.44.96", &addr.sin_addr.s_addr);

    ULTRA_LOG_INFO(g_logger) << "begin connect";
    int rt = connect(sock, (const sockaddr *) &addr, sizeof(addr));
    ULTRA_LOG_INFO(g_logger) << "connect rt=" << rt << " errno=" << errno;

    if (rt) {
        return;
    }

    const char data[] = "GET / HTTP/1.0\r\n\r\n";
    rt = send(sock, data, sizeof(data), 0);
    ULTRA_LOG_INFO(g_logger) << "send rt=" << rt << " errno=" << errno;

    if (rt <= 0) {
        return;
    }

    std::string buff;
    buff.resize(4096);

    rt = recv(sock, &buff[0], buff.size(), 0);
    ULTRA_LOG_INFO(g_logger) << "recv rt=" << rt << " errno=" << errno;

    if (rt <= 0) {
        return;
    }

    buff.resize(rt);
    ULTRA_LOG_INFO(g_logger) << buff;
}


int main(int argc, char *argv[]) {

    ultra::EnvMgr::GetInstance()->init(argc, argv);
    ultra::Config::LoadFromConfDir(ultra::EnvMgr::GetInstance()->getConfigPath());

    test_sleep();

    ultra::IOManager iom;
    iom.schedule(test_sock);

    ULTRA_LOG_INFO(g_logger) << "main end";

    return 0;

}