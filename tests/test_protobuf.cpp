//
// Created by lmy on 2023/2/24.
//

#include "ultra/rpc/rpc_protobuf.pb.h"


int main() {
    ultraRPC::ultraProtocol proto;

    proto.set_magic(8000);

    proto.set_sequence_id(6830920);
    proto.set_version(1);

    ultraRPC::ultraProtocol::MsgContent mess;
    mess.set_content("hello");


    return 0;
}