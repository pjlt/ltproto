cmake_minimum_required(VERSION 3.20)
project(ltproto)

option(GENERATE_LTPROTO OFF)

message(VERBOSE "LT_ANDROID=${LT_ANDROID}")
if (LT_WINDOWS OR LT_LINUX OR LT_MAC)
    set(PROTOC_PATH ${Protobuf_PROTOC_EXECUTABLE})
elseif (LT_ANDROID AND WIN32) # 在Windows上开发安卓
    set(PROTOC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/prebuilt/protoc/bin/protoc.exe)
elseif (LT_ANDROID AND APPLE)
    set(PROTOC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/prebuilt/protoc-mac/bin/protoc)
elseif (LT_ANDROID AND UNIX)
    set(PROTOC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/prebuilt/protoc/bin/protoc)
    # fixme
    set(PROTOC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/prebuilt/protoc-mac/bin/protoc)
else()
    message(VERBOSE "Unsupported platform")
endif()


function(lt_generate_protobuf_cpp SRCS HDRS)
    set(_SRCS)
    set(_HDRS)
    foreach (_file ${ARGN})
        string(REPLACE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} _file1 ${_file})
        string(REPLACE ".proto" ".pb.cc" cc_file ${_file1})
        string(REPLACE ".proto" ".pb.h" h_file ${_file1})
        list(APPEND _SRCS ${cc_file})
        list(APPEND _HDRS ${h_file})
    endforeach()
    if (LT_LINUX)
        add_custom_command(
                OUTPUT ${_SRCS} ${_HDRS}
                # Linux上目前编译的动态库，需要指定LD_LIBRARY_PATH。考虑将protoc统一成下载官方binary，而不是自己编译
                COMMAND ${CMAKE_COMMAND} -E env LD_LIBRARY_PATH=${LT_ROOT_DIR}/third_party/prebuilt/protobuf/linux/lib ${PROTOC_PATH}
                ARGS --cpp_out=lite:${CMAKE_CURRENT_BINARY_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} ${ARGN}
                DEPENDS ${ARGN}
        )
    else()
        add_custom_command(
                OUTPUT ${_SRCS} ${_HDRS}
                COMMAND ${PROTOC_PATH}
                ARGS --cpp_out=lite:${CMAKE_CURRENT_BINARY_DIR} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} ${ARGN}
                DEPENDS ${ARGN}
        )
    endif()
    set(${SRCS} ${_SRCS} PARENT_SCOPE)
    set(${HDRS} ${_HDRS} PARENT_SCOPE)
endfunction()

set(LT_PROTOS
    #root
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/error_code.proto
    #common
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/common/keep_alive.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/common/keep_alive_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/common/streaming_params.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/common/video_codec_type.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/common/transport_type.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/common/clipboard.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/common/os_type.proto
    #server
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/allocate_device_id.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/allocate_device_id_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/close_connection.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/connection_type.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/login_device.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/login_device_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/login_user.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/login_user_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/open_connection.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/open_connection_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/request_connection.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/request_connection_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/new_version.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/server/redirect_server_address.proto
    #signaling
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/signaling/join_room.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/signaling/join_room_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/signaling/signaling_message.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/signaling/signaling_message_ack.proto
    #client2app
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2app/client_status.proto
    #client2service
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2service/time_sync.proto
    #client2worker
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/audio_data.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/controller_added_removed.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/controller_response.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/controller_status.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/keyboard_event.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/mouse_event.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/request_keyframe.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/send_side_stat.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/start_transmission.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/start_transmission_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/stop_transmission.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/video_frame.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/video_frame_ack1.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/video_frame_ack2.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/switch_mouse_mode.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/cursor_info.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/touch_event.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/change_streaming_params.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/change_streaming_params_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/client2worker/switch_monitor.proto
    #service2app
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/service2app/confirm_connection.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/service2app/confirm_connection_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/service2app/accepted_connection.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/service2app/disconnected_connection.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/service2app/connection_status.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/service2app/operate_connection.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/service2app/service_status.proto
    #worker2service
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/worker2service/reconfigure_video_encoder.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/worker2service/start_working.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/worker2service/start_working_ack.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/worker2service/stop_working.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/worker2service/network_changed.proto
    #app
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/app/pull_file.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/app/file_chunk.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ltproto/app/file_chunk_ack.proto
)

lt_generate_protobuf_cpp(GENERATED_PROTO_CC GENERATED_PROTO_H ${LT_PROTOS})

if(GENERATE_LTPROTO)
    add_custom_command(
        OUTPUT
            ${CMAKE_CURRENT_SOURCE_DIR}/include/ltproto/ltproto.h
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ltproto.cpp
        COMMAND
            python ${CMAKE_CURRENT_SOURCE_DIR}/gencpp.py
        DEPENDS
            ${CMAKE_CURRENT_SOURCE_DIR}/defines.json
    )
endif()

add_library(${PROJECT_NAME} STATIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include/ltproto/ltproto.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ltproto.cpp
    ${GENERATED_PROTO_CC}
    ${GENERATED_PROTO_H}
)


target_link_libraries(${PROJECT_NAME}
    PRIVATE
        protobuf::libprotobuf-lite
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(
	TARGETS ${PROJECT_NAME}
)
