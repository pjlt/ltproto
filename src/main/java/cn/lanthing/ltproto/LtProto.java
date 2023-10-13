package cn.lanthing.ltproto;

public enum LtProto {

    LoginDevice(1001, "cn.lanthing.ltproto.server.LoginDeviceProto$LoginDevice"),
    LoginDeviceAck(1002, "cn.lanthing.ltproto.server.LoginDeviceAckProto$LoginDeviceAck"),

    LoginUser(1003, "cn.lanthing.ltproto.server.LoginUserProto$LoginUser"),

    LoginUserAck(1004, "cn.lanthing.ltproto.server.LoginUserAckProto$LoginUserAck"),

    AllocateDeviceID(1005, "cn.lanthing.ltproto.server.AllocateDeviceIDProto$AllocateDeviceID"),

    AllocateDeviceIDAck(1006, "cn.lanthing.ltproto.server.AllocateDeviceIDAckProto$AllocateDeviceIDAck"),

    RequestConnection(1007, "cn.lanthing.ltproto.server.RequestConnectionProto$RequestConnection"),

    RequestConnectionAck(1008, "cn.lanthing.ltproto.server.RequestConnectionAckProto$RequestConnectionAck"),

    OpenConnection(1009, "cn.lanthing.ltproto.server.OpenConnectionProto$OpenConnection"),

    OpenConnectionAck(1010, "cn.lanthing.ltproto.server.OpenConnectionAckProto$OpenConnectionAck"),

    CloseConnection(1011, "cn.lanthing.ltproto.server.CloseConnectionProto$CloseConnection"),

    SignalingMessage(2001, "cn.lanthing.ltproto.signaling.SignalingMessageProto$SignalingMessage"),

    SignalingMessageAck(2002, "cn.lanthing.ltproto.signaling.SignalingMessageAckProto$SignalingMessageAck"),

    JoinRoom(2003, "cn.lanthing.ltproto.signaling.JoinRoomProto$JoinRoom"),

    JoinRoomAck(2004, "cn.lanthing.ltproto.signaling.JoinRoomAckProto$JoinRoomAck");



    public final long ID;
    public final String className;

    LtProto(int id, String name) {
        ID = id;
        className = name;
    }
}
