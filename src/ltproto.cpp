//这个文件是自动生成的，请不要手动修改.
#include <ltproto/ltproto.h>
#include <ltproto/common/keep_alive.pb.h>
#include <ltproto/common/streaming_params.pb.h>
#include <ltproto/server/login_device.pb.h>
#include <ltproto/server/login_device_ack.pb.h>
#include <ltproto/server/login_user.pb.h>
#include <ltproto/server/login_user_ack.pb.h>
#include <ltproto/server/allocate_device_id.pb.h>
#include <ltproto/server/allocate_device_id_ack.pb.h>
#include <ltproto/server/request_connection.pb.h>
#include <ltproto/server/request_connection_ack.pb.h>
#include <ltproto/server/open_connection.pb.h>
#include <ltproto/server/open_connection_ack.pb.h>
#include <ltproto/server/close_connection.pb.h>
#include <ltproto/signaling/signaling_message.pb.h>
#include <ltproto/signaling/signaling_message_ack.pb.h>
#include <ltproto/signaling/join_room.pb.h>
#include <ltproto/signaling/join_room_ack.pb.h>
#include <ltproto/client2service/time_sync.pb.h>
#include <ltproto/client2worker/audio_data.pb.h>
#include <ltproto/client2worker/controller_added_removed.pb.h>
#include <ltproto/client2worker/controller_status.pb.h>
#include <ltproto/client2worker/controller_response.pb.h>
#include <ltproto/client2worker/mouse_event.pb.h>
#include <ltproto/client2worker/keyboard_event.pb.h>
#include <ltproto/client2worker/send_side_stat.pb.h>
#include <ltproto/client2worker/request_keyframe.pb.h>
#include <ltproto/client2worker/video_frame.pb.h>
#include <ltproto/client2worker/video_frame_ack1.pb.h>
#include <ltproto/client2worker/video_frame_ack2.pb.h>
#include <ltproto/client2worker/start_transmission.pb.h>
#include <ltproto/client2worker/start_transmission_ack.pb.h>
#include <ltproto/client2worker/stop_transmission.pb.h>
#include <ltproto/service2app/confirm_connection.pb.h>
#include <ltproto/service2app/confirm_connection_ack.pb.h>
#include <ltproto/service2app/accepted_connection.pb.h>
#include <ltproto/service2app/disconnected_connection.pb.h>
#include <ltproto/service2app/connection_status.pb.h>
#include <ltproto/service2app/operate_connection.pb.h>
#include <ltproto/worker2service/reconfigure_video_encoder.pb.h>
#include <ltproto/worker2service/start_working.pb.h>
#include <ltproto/worker2service/start_working_ack.pb.h>
#include <ltproto/worker2service/stop_working.pb.h>


namespace ltproto
{

std::shared_ptr<google::protobuf::MessageLite> create_by_type(uint32_t _type)
{
    using namespace type;
    switch (_type) {
    case kKeepAlive:
        return std::make_shared<common::KeepAlive>();
    case kStreamingParams:
        return std::make_shared<common::StreamingParams>();
    case kLoginDevice:
        return std::make_shared<server::LoginDevice>();
    case kLoginDeviceAck:
        return std::make_shared<server::LoginDeviceAck>();
    case kLoginUser:
        return std::make_shared<server::LoginUser>();
    case kLoginUserAck:
        return std::make_shared<server::LoginUserAck>();
    case kAllocateDeviceID:
        return std::make_shared<server::AllocateDeviceID>();
    case kAllocateDeviceIDAck:
        return std::make_shared<server::AllocateDeviceIDAck>();
    case kRequestConnection:
        return std::make_shared<server::RequestConnection>();
    case kRequestConnectionAck:
        return std::make_shared<server::RequestConnectionAck>();
    case kOpenConnection:
        return std::make_shared<server::OpenConnection>();
    case kOpenConnectionAck:
        return std::make_shared<server::OpenConnectionAck>();
    case kCloseConnection:
        return std::make_shared<server::CloseConnection>();
    case kSignalingMessage:
        return std::make_shared<signaling::SignalingMessage>();
    case kSignalingMessageAck:
        return std::make_shared<signaling::SignalingMessageAck>();
    case kJoinRoom:
        return std::make_shared<signaling::JoinRoom>();
    case kJoinRoomAck:
        return std::make_shared<signaling::JoinRoomAck>();
    case kTimeSync:
        return std::make_shared<client2service::TimeSync>();
    case kAudioData:
        return std::make_shared<client2worker::AudioData>();
    case kControllerAddedRemoved:
        return std::make_shared<client2worker::ControllerAddedRemoved>();
    case kControllerStatus:
        return std::make_shared<client2worker::ControllerStatus>();
    case kControllerResponse:
        return std::make_shared<client2worker::ControllerResponse>();
    case kMouseEvent:
        return std::make_shared<client2worker::MouseEvent>();
    case kKeyboardEvent:
        return std::make_shared<client2worker::KeyboardEvent>();
    case kSendSideStat:
        return std::make_shared<client2worker::SendSideStat>();
    case kRequestKeyframe:
        return std::make_shared<client2worker::RequestKeyframe>();
    case kVideoFrame:
        return std::make_shared<client2worker::VideoFrame>();
    case kVideoFrameAck1:
        return std::make_shared<client2worker::VideoFrameAck1>();
    case kVideoFrameAck2:
        return std::make_shared<client2worker::VideoFrameAck2>();
    case kStartTransmission:
        return std::make_shared<client2worker::StartTransmission>();
    case kStartTransmissionAck:
        return std::make_shared<client2worker::StartTransmissionAck>();
    case kStopTransmission:
        return std::make_shared<client2worker::StopTransmission>();
    case kConfirmConnection:
        return std::make_shared<service2app::ConfirmConnection>();
    case kConfirmConnectionAck:
        return std::make_shared<service2app::ConfirmConnectionAck>();
    case kAcceptedConnection:
        return std::make_shared<service2app::AcceptedConnection>();
    case kDisconnectedConnection:
        return std::make_shared<service2app::DisconnectedConnection>();
    case kConnectionStatus:
        return std::make_shared<service2app::ConnectionStatus>();
    case kOperateConnection:
        return std::make_shared<service2app::OperateConnection>();
    case kReconfigureVideoEncoder:
        return std::make_shared<worker2service::ReconfigureVideoEncoder>();
    case kStartWorking:
        return std::make_shared<worker2service::StartWorking>();
    case kStartWorkingAck:
        return std::make_shared<worker2service::StartWorkingAck>();
    case kStopWorking:
        return std::make_shared<worker2service::StopWorking>();
    default:
        return nullptr;
    }
}

uint32_t id(const std::shared_ptr<common::KeepAlive>&)
{
    return type::kKeepAlive;
}
uint32_t id(const std::shared_ptr<common::StreamingParams>&)
{
    return type::kStreamingParams;
}
uint32_t id(const std::shared_ptr<server::LoginDevice>&)
{
    return type::kLoginDevice;
}
uint32_t id(const std::shared_ptr<server::LoginDeviceAck>&)
{
    return type::kLoginDeviceAck;
}
uint32_t id(const std::shared_ptr<server::LoginUser>&)
{
    return type::kLoginUser;
}
uint32_t id(const std::shared_ptr<server::LoginUserAck>&)
{
    return type::kLoginUserAck;
}
uint32_t id(const std::shared_ptr<server::AllocateDeviceID>&)
{
    return type::kAllocateDeviceID;
}
uint32_t id(const std::shared_ptr<server::AllocateDeviceIDAck>&)
{
    return type::kAllocateDeviceIDAck;
}
uint32_t id(const std::shared_ptr<server::RequestConnection>&)
{
    return type::kRequestConnection;
}
uint32_t id(const std::shared_ptr<server::RequestConnectionAck>&)
{
    return type::kRequestConnectionAck;
}
uint32_t id(const std::shared_ptr<server::OpenConnection>&)
{
    return type::kOpenConnection;
}
uint32_t id(const std::shared_ptr<server::OpenConnectionAck>&)
{
    return type::kOpenConnectionAck;
}
uint32_t id(const std::shared_ptr<server::CloseConnection>&)
{
    return type::kCloseConnection;
}
uint32_t id(const std::shared_ptr<signaling::SignalingMessage>&)
{
    return type::kSignalingMessage;
}
uint32_t id(const std::shared_ptr<signaling::SignalingMessageAck>&)
{
    return type::kSignalingMessageAck;
}
uint32_t id(const std::shared_ptr<signaling::JoinRoom>&)
{
    return type::kJoinRoom;
}
uint32_t id(const std::shared_ptr<signaling::JoinRoomAck>&)
{
    return type::kJoinRoomAck;
}
uint32_t id(const std::shared_ptr<client2service::TimeSync>&)
{
    return type::kTimeSync;
}
uint32_t id(const std::shared_ptr<client2worker::AudioData>&)
{
    return type::kAudioData;
}
uint32_t id(const std::shared_ptr<client2worker::ControllerAddedRemoved>&)
{
    return type::kControllerAddedRemoved;
}
uint32_t id(const std::shared_ptr<client2worker::ControllerStatus>&)
{
    return type::kControllerStatus;
}
uint32_t id(const std::shared_ptr<client2worker::ControllerResponse>&)
{
    return type::kControllerResponse;
}
uint32_t id(const std::shared_ptr<client2worker::MouseEvent>&)
{
    return type::kMouseEvent;
}
uint32_t id(const std::shared_ptr<client2worker::KeyboardEvent>&)
{
    return type::kKeyboardEvent;
}
uint32_t id(const std::shared_ptr<client2worker::SendSideStat>&)
{
    return type::kSendSideStat;
}
uint32_t id(const std::shared_ptr<client2worker::RequestKeyframe>&)
{
    return type::kRequestKeyframe;
}
uint32_t id(const std::shared_ptr<client2worker::VideoFrame>&)
{
    return type::kVideoFrame;
}
uint32_t id(const std::shared_ptr<client2worker::VideoFrameAck1>&)
{
    return type::kVideoFrameAck1;
}
uint32_t id(const std::shared_ptr<client2worker::VideoFrameAck2>&)
{
    return type::kVideoFrameAck2;
}
uint32_t id(const std::shared_ptr<client2worker::StartTransmission>&)
{
    return type::kStartTransmission;
}
uint32_t id(const std::shared_ptr<client2worker::StartTransmissionAck>&)
{
    return type::kStartTransmissionAck;
}
uint32_t id(const std::shared_ptr<client2worker::StopTransmission>&)
{
    return type::kStopTransmission;
}
uint32_t id(const std::shared_ptr<service2app::ConfirmConnection>&)
{
    return type::kConfirmConnection;
}
uint32_t id(const std::shared_ptr<service2app::ConfirmConnectionAck>&)
{
    return type::kConfirmConnectionAck;
}
uint32_t id(const std::shared_ptr<service2app::AcceptedConnection>&)
{
    return type::kAcceptedConnection;
}
uint32_t id(const std::shared_ptr<service2app::DisconnectedConnection>&)
{
    return type::kDisconnectedConnection;
}
uint32_t id(const std::shared_ptr<service2app::ConnectionStatus>&)
{
    return type::kConnectionStatus;
}
uint32_t id(const std::shared_ptr<service2app::OperateConnection>&)
{
    return type::kOperateConnection;
}
uint32_t id(const std::shared_ptr<worker2service::ReconfigureVideoEncoder>&)
{
    return type::kReconfigureVideoEncoder;
}
uint32_t id(const std::shared_ptr<worker2service::StartWorking>&)
{
    return type::kStartWorking;
}
uint32_t id(const std::shared_ptr<worker2service::StartWorkingAck>&)
{
    return type::kStartWorkingAck;
}
uint32_t id(const std::shared_ptr<worker2service::StopWorking>&)
{
    return type::kStopWorking;
}

std::optional<Packet> Packet::create(const Message& payload, bool need_xor)
{
    need_xor = false; // XXX
    Packet pkt{};
    pkt.header.magic = kMagicV1;
    pkt.header.xor_key = 0;
    pkt.header.checksum = 0;
    pkt.header.payload_size = static_cast<uint32_t>(payload.msg->ByteSizeLong()) + 4;
    pkt.payload = std::shared_ptr<uint8_t>(new uint8_t[pkt.header.payload_size]);
    *(uint32_t*)pkt.payload.get() = payload.type;
    if (payload.msg->SerializeToArray(pkt.payload.get() + 4, pkt.header.payload_size - 4)) {
        if (need_xor) {
            pkt.header.xor_key = ::rand() % 254 + 1;
            for (uint32_t i = 0; i < pkt.header.payload_size; i++) {
                *pkt.payload.get() ^= (uint8_t)pkt.header.xor_key;
            }
        }
        return pkt;
    }
    else {
        return std::nullopt;
    }
}

std::optional<Packet> Packet::create(const std::shared_ptr<uint8_t>& data, uint32_t len, bool need_xor)
{
    need_xor = false; // XXX
    Packet pkt{};
    pkt.header.magic = kMagicV1;
    pkt.header.xor_key = 0;
    pkt.header.checksum = 0;
    pkt.header.payload_size = len;
    pkt.payload = data;
    if (need_xor) {
        pkt.header.xor_key = ::rand() % 254 + 1;
        for (uint32_t i = 0; i < pkt.header.payload_size; i++) {
            *pkt.payload.get() ^= (uint8_t)pkt.header.xor_key;
        }
    }
    return pkt;
}

void Parser::clear()
{
    buffer_.clear();
    packets_.clear();
    messages_.clear();
}

void Parser::push_buffer(const uint8_t* buff, uint32_t size)
{
    buffer_.insert(buffer_.cend(), buff, buff + size);
}

bool Parser::parse_buffer()
{
    if (!parse_net_packets()) {
        return false;
    }
    parse_bussiness_messages();
    return true;
}

std::optional<Message> Parser::pop_message()
{
    if (messages_.empty()) {
        return std::nullopt;
    }
    else {
        auto top = messages_.front();
        messages_.pop_front();
        return top;
    }
}

bool Parser::parse_net_packets()
{
    size_t total_erase_size = 0;
    while (buffer_.size() - total_erase_size > 0) {
        ltproto::Packet packet;
        int ret_value = parse_net_packet(
            buffer_.data() + total_erase_size,
            static_cast<uint32_t>(buffer_.size() - total_erase_size),
            packet);
        if (ret_value > 0) {
            total_erase_size += ret_value;
            packets_.push_back(packet);
            continue;
        }
        else if (ret_value < 0) {
            break; // 数据不足
        }
        else if (ret_value == 0) {
            return false; // 解析异常
        }
    }

    if (buffer_.size() == total_erase_size)
        buffer_.clear();
    else
        buffer_.erase(buffer_.begin(), buffer_.begin() + total_erase_size);

    return true;
}
int Parser::parse_net_packet(const uint8_t* data, uint32_t size, ltproto::Packet& packet)
{
    if (size < ltproto::kMsgHeaderSize) {
        return -1;
    }
    packet.header = *reinterpret_cast<const ltproto::PacketHeader*>(data);
    // 长度是否足够一个包
    if (size < packet.header.payload_size + ltproto::kMsgHeaderSize) {
        return -1;
    }
    // 长度是否超出20MB限制
    if (size > 20 * 1024 * 1024) {
        return 0;
    }
    std::shared_ptr<uint8_t> payload{ new uint8_t[packet.header.payload_size] };
    ::memcpy(payload.get(), data + ltproto::kMsgHeaderSize, packet.header.payload_size);
    if (packet.header.xor_key != 0) {
        for (uint32_t i = 0; i < packet.header.payload_size; i++) {
            *(payload.get() + i) ^= packet.header.xor_key;
        }
    }
    packet.payload = payload;
    return static_cast<int>(packet.header.payload_size + ltproto::kMsgHeaderSize);
}
void Parser::parse_bussiness_messages()
{
    while (!packets_.empty()) {
        auto& packet = packets_.front();
        uint32_t type = *reinterpret_cast<const uint32_t*>(packet.payload.get());
        std::shared_ptr<google::protobuf::MessageLite> msg = create_by_type(type);
        if (msg == nullptr) {
            //unknown msg type
        }
        else {
            bool success = msg->ParseFromArray(packet.payload.get() + 4, packet.header.payload_size - 4);
            if (!success) {
                //error
            }
            else {
                messages_.push_back({ type, msg });
            }

        }
        packets_.pop_front();
    }
}

} // namespace ltproto
