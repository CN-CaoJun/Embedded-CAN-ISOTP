#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "stdint.h"
#include "time.h"
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <linux/can.h>
#include <linux/can/raw.h>

// 发送CAN帧
void send_can_frame(int s, canid_t can_id, const uint8_t *data, size_t len) {
    struct can_frame frame;
    frame.can_id = can_id;
    frame.can_dlc = len;
    memcpy(frame.data, data, len);

    if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        perror("Write");
        exit(EXIT_FAILURE);
    }
}

// 接收CAN帧
void receive_can_frame(int s) {
    struct can_frame frame;

    if (read(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        perror("Read");
        exit(EXIT_FAILURE);
    }

    printf("Received CAN frame ID: 0x%X DLC: %d Data: ", frame.can_id, frame.can_dlc);
    for (int i = 0; i < frame.can_dlc; i++) {
        printf("%02X ", frame.data[i]);
    }
    printf("\n");
}

int s;
int main() {
    struct sockaddr_can addr;
    struct ifreq ifr;

    // 创建CAN套接字
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Socket");
        exit(EXIT_FAILURE);
    }

    // 绑定到vcan0接口
    strcpy(ifr.ifr_name, "vcan0");
    ioctl(s, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind");
        close(s);
        exit(EXIT_FAILURE);
    }

    // 发送CAN帧示例
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    send_can_frame(s, 0x123, data, sizeof(data));

    while (1) {
        receive_can_frame(s);
        // sleep_ms(5);
    }

    close(s);
    return 0;
}