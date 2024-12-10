#include <stdint.h>
#include "assert.h"
#include "isotp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <time.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <linux/can.h>
#include <linux/can/raw.h>

/* user implemented, print debug message */
void isotp_user_debug(const char* message, ...)
{   
    printf("DEBUG -- ");
    printf("%s", message);
}

/* user implemented, send can message. should return ISOTP_RET_OK when success.
*/
extern int s;
extern void send_can_frame(int s, canid_t can_id, const uint8_t *data, size_t len);
int  isotp_user_send_can(const uint32_t arbitration_id,
                         const uint8_t* data, const uint8_t size)
{
    send_can_frame(s,arbitration_id,data,size);
    return 0;
}

/* user implemented, get millisecond */
uint32_t isotp_user_get_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    // printf("Current time in milliseconds: %lu\n", milliseconds);
    return milliseconds;
}