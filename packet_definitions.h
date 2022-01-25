#pragma once 

#pragma pack(1)
typedef struct packet_hdr
{
    char gid; // 100 [realsense] , 101 [rgb]
    char pid; // depth_color , depth, color, 
    unsigned int len;
}PACKET_HDR, *PPACKET_HDR;
#pragma pack()


enum GROUP_ID
{
    GID_REALSENSE=100,
    GID_RGB

};
enum PACKET_ID
{
    PID_VIDEOTYPE_DEPTH_COLOR=1,
    PID_VIDEOTYPE_DEPTH,
    PID_VIDEOTYPE_COLOR,
    PID_COMMAND_MESSAGE,
    PID_COMMAND_PREDICT
};
