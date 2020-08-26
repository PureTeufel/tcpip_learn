/**********************************************************
 > File Name: peek_send.c
 > Author: PureTeufel
 > Mail: PureTeufel@163.com
 > Created Time: Tue 25 Aug 2020 08:03:55 PM CST
**********************************************************/

#include "err_handle.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
    int sock;
    struct sockaddr_in send_adr;
    if (argc != 3) {
        printf("Usage : %s <IP> <Port>\n", argv[0]);
        exit(0);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&send_adr, 0, sizeof(send_adr));
    send_adr.sin_family = AF_INET;
    send_adr.sin_addr.s_addr = inet_addr(argv[1]);
    send_adr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&send_adr, sizeof(send_adr)) == -1)
        error_handling("connect() error");

    write(sock, "123", sizeof("123"));
    close(sock);

    return 0;
}
