//
// Created by lmy on 2023/2/22.
//

#ifndef ULTRASERVER_PROTOCOL_H
#define ULTRASERVER_PROTOCOL_H

#include <memory>
#include <sstream>
#include "ultra/bytearray.h"


//RPC协议格式
/*
 * 私有通信协议
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |  BYTE  |        |        |        |        |        |        |        |        |        |        |             ........                                                           |
 * +--------------------------------------------+--------+--------------------------+--------+-----------------+--------+--------+--------+--------+--------+--------+-----------------+
 * |  magic | version|  type  |          sequence id              |          content length           |             content byte[]                                                     |
 * +--------+-----------------------------------------------------------------------------------------------------------------------------+--------------------------------------------+
 * 第一个字节是魔法数。
 * 第二个字节代表协议版本号，以便对协议进行扩展，使用不同的协议解析器。
 * 第三个字节是请求类型，如心跳包，rpc请求。
 * 第四个字节开始是一个32位序列号。
 * 第八个字节开始的四字节表示消息长度，即后面要接收的内容长度。
 */

namespace ultra {
    namespace rpc {
        class Protocol {
        public:
            using ptr = std::shared_ptr<Protocol>;

            static constexpr uint8_t MAGIC = 0x37;
            static constexpr uint8_t DEFAULT_VERSION = 0x02;
            static constexpr uint8_t BASE_LENGTH = 11;

            enum class MsgType : uint8_t {
                HEARTBEAT_PACKET,       // 心跳包
                RPC_PROVIDER,           // 向服务中心声明为provider
                RPC_CONSUMER,           // 向服务中心声明为consumer

                RPC_REQUEST,            // 通用请求
                RPC_RESPONSE,           // 通用响应

                RPC_METHOD_REQUEST,     // 请求方法调用
                RPC_METHOD_RESPONSE,    // 响应方法调用

                RPC_SERVICE_REGISTER,   // 向中心注册服务
                RPC_SERVICE_REGISTER_RESPONSE,

                RPC_SERVICE_DISCOVER,   // 向中心请求服务发现
                RPC_SERVICE_DISCOVER_RESPONSE,

                RPC_PUBSUB_REQUEST,     // 发布订阅
                RPC_PUBSUB_RESPONSE,
            };

            static Protocol::ptr Create(MsgType type, const std::string &content, uint32_t id = 0) {
                Protocol::ptr proto = std::make_shared<Protocol>();
                proto->setMsgType(type);
                proto->setContent(content);
                proto->setSequenceId(id);
                return proto;
            }

            static Protocol::ptr HeartBeat() {
                static Protocol::ptr Heartbeat = Protocol::Create(Protocol::MsgType::HEARTBEAT_PACKET, "");
                return Heartbeat;
            }

            uint8_t getMagic() const { return m_magic; }

            uint8_t getVersion() const { return m_version; }

            MsgType getMsgType() const { return static_cast<MsgType>(m_type); }

            uint32_t getSequenceId() const { return m_sequence_id; }

            uint32_t getContentLength() const { return m_content_length; }

            const std::string &getContent() const { return m_content; }

            void setMagic(uint8_t magic) { m_magic = magic; }

            void setVersion(uint8_t version) { m_version = version; }

            void setMsgType(MsgType type) { m_type = static_cast<uint8_t>(type); }

            void setSequenceId(uint32_t id) { m_sequence_id = id; }

            void setContentLength(uint32_t len) { m_content_length = len; }

            void setContent(const std::string &content) { m_content = content; }

            ByteArray::ptr encodeMeta() {
                ByteArray::ptr bt = std::make_shared<ByteArray>();
                bt->writeFuint8(m_magic);
                bt->writeFuint8(m_version);
                bt->writeFuint8(m_type);
                bt->writeFuint32(m_sequence_id);
                bt->writeFuint32(m_content.size());
                bt->setPosition(0);
                return bt;
            }

            ByteArray::ptr encode() {
                ByteArray::ptr bt = std::make_shared<ByteArray>();
                bt->writeFuint8(m_magic);
                bt->writeFuint8(m_version);
                bt->writeFuint8(m_type);
                bt->writeFuint32(m_sequence_id);
                bt->writeStringF32(m_content);
                bt->setPosition(0);
                return bt;
            }

            void decodeMeta(ByteArray::ptr bt) {
                m_magic = bt->readFuint8();
                m_version = bt->readFuint8();
                m_type = bt->readFuint8();
                m_sequence_id = bt->readFuint32();
                m_content_length = bt->readFuint32();
            }

            void decode(ByteArray::ptr bt) {
                m_magic = bt->readFuint8();
                m_version = bt->readFuint8();
                m_type = bt->readFuint8();
                m_sequence_id = bt->readFuint32();
                m_content = bt->readStringF32();
                m_content_length = m_content.size();
            }

            std::string toString() {
                std::stringstream ss;
                ss << "[ magic=" << m_magic
                   << " version=" << m_version
                   << " type=" << m_type
                   << " id=" << m_sequence_id
                   << " length=" << m_content_length
                   << " content=" << m_content
                   << " ]";
                return ss.str();
            }

        private:
            uint8_t m_magic = MAGIC;
            uint8_t m_version = DEFAULT_VERSION;
            uint8_t m_type = 0;
            uint32_t m_sequence_id = 0;
            uint32_t m_content_length = 0;
            std::string m_content;


        };
    }
}


#endif //ULTRASERVER_PROTOCOL_H
