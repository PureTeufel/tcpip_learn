/**********************************************************
 > File Name: sock_type.c
 > Author: PureTeufel
 > Mail: PureTeufel@163.com
 > Created Time: Thu 20 Aug 2020 09:02:40 PM CST
**********************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include "err_handle.h"
#include <stdio.h>

int main()
{
    int tcp_sock, udp_sock;
    int buf = 1024 * 3;
    int state;
    socklen_t optlen;

    tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
    udp_sock = socket(PF_INET, SOCK_DGRAM, 0);
    printf("SOCK_STREAM: %d\n", SOCK_STREAM);
    printf("SOCK_STREAM: %d\n", SOCK_DGRAM);

    optlen = sizeof(buf);

    state = setsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void*)&buf, optlen);
    if (state == -1)
        error_handling("setsockopt() error");
    printf("tcp send buf one: %d\n", buf);

    state = setsockopt(tcp_sock, SOL_SOCKET, SO_RCVBUF, (void*)&buf, optlen);
    if (state == -1)
        error_handling("setsockopt() error");
    printf("tcp recv buf two: %d\n", buf);

    state = setsockopt(udp_sock, SOL_SOCKET, SO_SNDBUF, (void*)&buf, optlen);
    if (state == -1)
        error_handling("setsockopt() error");
    printf("udp send buf one: %d\n", buf);

    state = setsockopt(udp_sock, SOL_SOCKET, SO_RCVBUF, (void*)&buf, optlen);
    if (state == -1)
        error_handling("setsockopt() error");
    printf("udp recv buf two: %d\n", buf);

    return 0;
}

