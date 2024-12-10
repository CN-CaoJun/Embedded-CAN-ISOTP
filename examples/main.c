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
#include <fcntl.h>  // For fcntl
#include <errno.h>  // For EAGAIN and EWOULDBLOCK
#include "isotp.h"

#define RET_OK 0
#define RET_NOK 1
#define RET_ERR 2
#define RET_NO_DATA 3 
/* Alloc IsoTpLink statically in RAM */
static IsoTpLink g_link;

/* Alloc send and receive buffer statically in RAM */
static uint8_t g_isotpRecvBuf[4095];
static uint8_t g_isotpSendBuf[4095];

void send_can_frame(int s, canid_t can_id, const uint8_t *data, size_t len)
{
    struct can_frame frame;
    frame.can_id = can_id;
    frame.can_dlc = len;
    memcpy(frame.data, data, len);

    if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame))
    {
        perror("Write");
        exit(EXIT_FAILURE);
    }
}

int receive_can_frame(int s, uint16_t *id, uint8_t *data, uint16_t *len)
{
    struct can_frame frame;

    // Set the socket to non-blocking mode
    int flags = fcntl(s, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl F_GETFL");
        return RET_ERR;
    }
    flags |= O_NONBLOCK;
    if (fcntl(s, F_SETFL, flags) == -1) {
        perror("fcntl F_SETFL");
        return RET_ERR;
    }

    ssize_t nbytes = read(s, &frame, sizeof(struct can_frame));
    if (nbytes == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            // No data available, handle accordingly
            return RET_NO_DATA;
        } else {
            perror("Read");
            return RET_ERR;
        }
    } else if (nbytes != sizeof(struct can_frame)) {
        fprintf(stderr, "Incomplete CAN frame read\n");
        return RET_ERR;
    }

    *id = frame.can_id;
    *len = frame.can_dlc;

    printf("Received CAN frame ID: 0x%X DLC: %d Data: ", frame.can_id, frame.can_dlc);
    for (int i = 0; i < frame.can_dlc; i++) {
        data[i] = frame.data[i];
        printf("%02X ", frame.data[i]);
    }
    printf("\n");

    return RET_OK;
}

int s;
int main(void)
{
    /* Initialize CAN and other peripherals */
    int ret;
    struct sockaddr_can addr;
    struct ifreq ifr;

    uint16_t receive_id = 0;
    uint8_t receiveid_data[8] = {0};
    uint16_t receiveid_len = 0;

    uint8_t payload[4095] = {0};
    uint16_t payload_size = 0;
    uint16_t out_size = 0;

    uint8_t send_route_control = 0;
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
    {
        perror("Socket");
        exit(EXIT_FAILURE);
    }

    strcpy(ifr.ifr_name, "vcan0");
    ioctl(s, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("Bind");
        close(s);
        exit(EXIT_FAILURE);
    }

    /* Initialize link, 0x7TT is the CAN ID you send with */
    isotp_init_link(&g_link, 0x739,
                    g_isotpSendBuf, sizeof(g_isotpSendBuf),
                    g_isotpRecvBuf, sizeof(g_isotpRecvBuf));
                    
    uint8_t sendbuf[100] = {0x00};

        for (int i = 0; i < 100; i++) {
            sendbuf[i] = i+1;
        }
                                                                                     

    while (1)
    {

        /* If receive any interested can message, call isotp_on_can_message to handle message */
        // ret = can_receive(&id, &data, &len);
        ret = receive_can_frame(s, &receive_id, receiveid_data, &receiveid_len);

        /* 0x7RR is CAN ID you want to receive */
        if (RET_OK == ret && 0x731 == receive_id)
        {
            isotp_on_can_message(&g_link, receiveid_data, receiveid_len);
        }

        /* Poll link to handle multiple frame transmition */
        isotp_poll(&g_link);

        /* You can receive message with isotp_receive.
           payload is upper layer message buffer, usually UDS;
           payload_size is payload buffer size;
           out_size is the actuall read size;
           */
        ret = isotp_receive(&g_link, payload, payload_size, &out_size);
        if (ISOTP_RET_OK == ret)
        {
            /* Handle received message */
            // printf("Received %d bytes\n", out_size);
            printf("Received OK!!!\n");
            send_route_control = 1;
        }

        /* And send message with isotp_send */
        if (send_route_control == 1)
        {
            ret = isotp_send(&g_link, sendbuf, 100);
            if (ISOTP_RET_OK == ret)
            {
                printf("send first OK!!!\n");
                send_route_control = 0;
            }
            else
            {
                /* An error occured */
            }
        }

        usleep(1000);
    }

    return;
}