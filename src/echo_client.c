/*************************************************
 > File Name: echo_client.c
 > Author: PureTeufel
 > Mail: PureTeufel@163.com
 > Created Time: Tue 25 Aug 2020 01:40:40 PM CST
***************************************************/

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "err_handle.h"
#include <sys/socket.h>

#define BUF_SIZE 30


int main(int argc, char** argv)
{
    int sock;
    struct sockaddr_in adr;
    char buf[BUF_SIZE];
    char msg[BUF_SIZE];

    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }
    
    memset(&adr, 0, sizeof(adr));
    adr.sin_family = AF_INET;
    adr.sin_addr.s_addr = inet_addr(argv[1]);
    adr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&adr, sizeof(adr)) == -1)
        error_handling("connect() error");
    else
        puts("Connected ...");

    while (1) {

        fgets(buf, BUF_SIZE, stdin);
        write(sock, buf, BUF_SIZE);
        read(sock, msg, BUF_SIZE); 
        printf("%s", msg);
    }

    close(sock);
    
    return 0;
}
