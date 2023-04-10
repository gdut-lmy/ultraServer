//
// Created by lmy on 2023/2/22.
//

#ifndef ULTRASERVER_RPC_SESSION_H
#define ULTRASERVER_RPC_SESSION_H


#include "ultra/streams/socket_stream.h"
#include "protocol.h"




namespace ultra {
    namespace rpc {
        class RpcSession : public SocketStream {
        public:
            using ptr = std::shared_ptr<RpcSession>;
            //using MutexType = type;

            RpcSession(Socket::ptr socket, bool ower = true);


            Protocol::ptr recvProtocol();

            ssize_t sendProtocol(Protocol::ptr protocol);


        };
    }
}


#endif //ULTRASERVER_RPC_SESSION_H
