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
    int sock_type;
    socklen_t optlen;
    int state;

    optlen = sizeof(sock_type);
    tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
    udp_sock = socket(PF_INET, SOCK_DGRAM, 0);
    printf("SOCK_STREAM: %d\n", SOCK_STREAM);
    printf("SOCK_STREAM: %d\n", SOCK_DGRAM);

    state = getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &optlen);
    if (state == -1)
        error_handling("getsockopt() error");
    printf("sock_type one: %d\n", sock_type);

    state = getsockopt(udp_sock, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &optlen);
    if (state == -1)
        error_handling("getsockopt() error");
    printf("sock_type two: %d\n", sock_type);

    return 0;
}

