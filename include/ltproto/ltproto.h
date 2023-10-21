//这个文件是自动生成的，请不要手动修改.
#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include <optional>
#include <deque>
#include <google/protobuf/message_lite.h>

namespace ltproto
{
    namespace common
    {
        class KeepAlive;
        class StreamingParams;
        class KeepAliveAck;
    }
    namespace server
    {
        class LoginDevice;
        class LoginDeviceAck;
        class LoginUser;
        class LoginUserAck;
        class AllocateDeviceID;
        class AllocateDeviceIDAck;
        class RequestConnection;
        class RequestConnectionAck;
        class OpenConnection;
        class OpenConnectionAck;
        class CloseConnection;
    }
    namespace signaling
    {
        class SignalingMessage;
        class SignalingMessageAck;
        class JoinRoom;
        class JoinRoomAck;
    }
    namespace client2app
    {
    }
    namespace client2service
    {
        class TimeSync;
    }
    namespace client2worker
    {
        class AudioData;
        class ControllerAddedRemoved;
        class ControllerStatus;
        class ControllerResponse;
        class MouseEvent;
        class KeyboardEvent;
        class SendSideStat;
        class RequestKeyframe;
        class VideoFrame;
        class VideoFrameAck1;
        class VideoFrameAck2;
        class StartTransmission;
        class StartTransmissionAck;
        class StopTransmission;
    }
    namespace service2app
    {
        class ConfirmConnection;
        class ConfirmConnectionAck;
        class AcceptedConnection;
        class DisconnectedConnection;
        class ConnectionStatus;
        class OperateConnection;
    }
    namespace worker2service
    {
        class ReconfigureVideoEncoder;
        class StartWorking;
        class StartWorkingAck;
        class StopWorking;
    }

    constexpr uint8_t kVersion2 = 2;

#pragma pack(push, 1)
    struct PacketHeader
    {
        uint32_t version : 8;
        uint32_t payload_size : 24;
        uint32_t checksum;
    };
#pragma pack(pop)

    constexpr uint32_t kMsgHeaderSize = sizeof(PacketHeader);
    static_assert(kMsgHeaderSize == 8);


    struct Message
    {
        uint32_t type;
        std::shared_ptr<google::protobuf::MessageLite> msg;
    };

    struct Packet
    {
        PacketHeader header;
        std::shared_ptr<uint8_t> payload;
        //头部暂时都是死的
        static std::optional<Packet> create(const Message& payload, bool need_xor);
        static std::optional<Packet> create(const std::shared_ptr<uint8_t>& data, uint32_t len, bool need_xor);
    };
    namespace type
    {

        constexpr uint32_t kFirstProtocol = 0;
        constexpr uint32_t kKeepAlive = 1;
        constexpr uint32_t kStreamingParams = 2;
        constexpr uint32_t kKeepAliveAck = 3;
        constexpr uint32_t kLoginDevice = 1001;
        constexpr uint32_t kLoginDeviceAck = 1002;
        constexpr uint32_t kLoginUser = 1003;
        constexpr uint32_t kLoginUserAck = 1004;
        constexpr uint32_t kAllocateDeviceID = 1005;
        constexpr uint32_t kAllocateDeviceIDAck = 1006;
        constexpr uint32_t kRequestConnection = 1007;
        constexpr uint32_t kRequestConnectionAck = 1008;
        constexpr uint32_t kOpenConnection = 1009;
        constexpr uint32_t kOpenConnectionAck = 1010;
        constexpr uint32_t kCloseConnection = 1011;
        constexpr uint32_t kSignalingMessage = 2001;
        constexpr uint32_t kSignalingMessageAck = 2002;
        constexpr uint32_t kJoinRoom = 2003;
        constexpr uint32_t kJoinRoomAck = 2004;
        constexpr uint32_t kTimeSync = 4001;
        constexpr uint32_t kAudioData = 5001;
        constexpr uint32_t kControllerAddedRemoved = 5002;
        constexpr uint32_t kControllerStatus = 5003;
        constexpr uint32_t kControllerResponse = 5004;
        constexpr uint32_t kMouseEvent = 5005;
        constexpr uint32_t kKeyboardEvent = 5006;
        constexpr uint32_t kSendSideStat = 5007;
        constexpr uint32_t kRequestKeyframe = 5008;
        constexpr uint32_t kVideoFrame = 5009;
        constexpr uint32_t kVideoFrameAck1 = 5010;
        constexpr uint32_t kVideoFrameAck2 = 5011;
        constexpr uint32_t kStartTransmission = 5012;
        constexpr uint32_t kStartTransmissionAck = 5013;
        constexpr uint32_t kStopTransmission = 5014;
        constexpr uint32_t kConfirmConnection = 6001;
        constexpr uint32_t kConfirmConnectionAck = 6002;
        constexpr uint32_t kAcceptedConnection = 6003;
        constexpr uint32_t kDisconnectedConnection = 6004;
        constexpr uint32_t kConnectionStatus = 6005;
        constexpr uint32_t kOperateConnection = 6006;
        constexpr uint32_t kReconfigureVideoEncoder = 7001;
        constexpr uint32_t kStartWorking = 7002;
        constexpr uint32_t kStartWorkingAck = 7003;
        constexpr uint32_t kStopWorking = 7004;
        constexpr uint32_t kLastProtocol = 0xffffffff;
    } // namespace type


    std::shared_ptr<google::protobuf::MessageLite> create_by_type(uint32_t type);
    uint32_t id(const std::shared_ptr<common::KeepAlive>&);
    uint32_t id(const std::shared_ptr<common::StreamingParams>&);
    uint32_t id(const std::shared_ptr<common::KeepAliveAck>&);
    uint32_t id(const std::shared_ptr<server::LoginDevice>&);
    uint32_t id(const std::shared_ptr<server::LoginDeviceAck>&);
    uint32_t id(const std::shared_ptr<server::LoginUser>&);
    uint32_t id(const std::shared_ptr<server::LoginUserAck>&);
    uint32_t id(const std::shared_ptr<server::AllocateDeviceID>&);
    uint32_t id(const std::shared_ptr<server::AllocateDeviceIDAck>&);
    uint32_t id(const std::shared_ptr<server::RequestConnection>&);
    uint32_t id(const std::shared_ptr<server::RequestConnectionAck>&);
    uint32_t id(const std::shared_ptr<server::OpenConnection>&);
    uint32_t id(const std::shared_ptr<server::OpenConnectionAck>&);
    uint32_t id(const std::shared_ptr<server::CloseConnection>&);
    uint32_t id(const std::shared_ptr<signaling::SignalingMessage>&);
    uint32_t id(const std::shared_ptr<signaling::SignalingMessageAck>&);
    uint32_t id(const std::shared_ptr<signaling::JoinRoom>&);
    uint32_t id(const std::shared_ptr<signaling::JoinRoomAck>&);
    uint32_t id(const std::shared_ptr<client2service::TimeSync>&);
    uint32_t id(const std::shared_ptr<client2worker::AudioData>&);
    uint32_t id(const std::shared_ptr<client2worker::ControllerAddedRemoved>&);
    uint32_t id(const std::shared_ptr<client2worker::ControllerStatus>&);
    uint32_t id(const std::shared_ptr<client2worker::ControllerResponse>&);
    uint32_t id(const std::shared_ptr<client2worker::MouseEvent>&);
    uint32_t id(const std::shared_ptr<client2worker::KeyboardEvent>&);
    uint32_t id(const std::shared_ptr<client2worker::SendSideStat>&);
    uint32_t id(const std::shared_ptr<client2worker::RequestKeyframe>&);
    uint32_t id(const std::shared_ptr<client2worker::VideoFrame>&);
    uint32_t id(const std::shared_ptr<client2worker::VideoFrameAck1>&);
    uint32_t id(const std::shared_ptr<client2worker::VideoFrameAck2>&);
    uint32_t id(const std::shared_ptr<client2worker::StartTransmission>&);
    uint32_t id(const std::shared_ptr<client2worker::StartTransmissionAck>&);
    uint32_t id(const std::shared_ptr<client2worker::StopTransmission>&);
    uint32_t id(const std::shared_ptr<service2app::ConfirmConnection>&);
    uint32_t id(const std::shared_ptr<service2app::ConfirmConnectionAck>&);
    uint32_t id(const std::shared_ptr<service2app::AcceptedConnection>&);
    uint32_t id(const std::shared_ptr<service2app::DisconnectedConnection>&);
    uint32_t id(const std::shared_ptr<service2app::ConnectionStatus>&);
    uint32_t id(const std::shared_ptr<service2app::OperateConnection>&);
    uint32_t id(const std::shared_ptr<worker2service::ReconfigureVideoEncoder>&);
    uint32_t id(const std::shared_ptr<worker2service::StartWorking>&);
    uint32_t id(const std::shared_ptr<worker2service::StartWorkingAck>&);
    uint32_t id(const std::shared_ptr<worker2service::StopWorking>&);


    class Parser
    {
    public:
        Parser() = default;
        void clear();
        void push_buffer(const uint8_t* buff, uint32_t size);
        bool parse_buffer();
        std::optional<Message> pop_message();

    private:
        bool parse_net_packets();
        int parse_net_packet(const uint8_t* data, uint32_t size, ltproto::Packet& packet);
        void parse_bussiness_messages();

    private:
        std::vector<uint8_t> buffer_;
        std::deque<Packet> packets_;
        std::deque<Message> messages_;
    };

} // namespace ltproto
