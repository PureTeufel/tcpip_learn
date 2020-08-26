/**********************************************************
 > File Name: gethostbyaddr.c
 > Author: PureTeufel
 > Mail: PureTeufel@163.com
 > Created Time: Wed 26 Aug 2020 07:24:26 PM CST
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char** argv)
{
    int i;
    struct hostent *host;
    struct sockaddr_in addr;
    if (argc != 2) {
        printf("Usage : %s <IP> \n", argv[0]);
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    //inet_pton(AF_INET, argv[1], &addr.sin_addr.s_addr);
    host = gethostbyaddr((char*)&addr.sin_addr, 4, AF_INET);
    if (!host)
        puts("gethost... error");

    printf("Official name: %s \n", host->h_name);
    for (i = 0; host->h_aliases[i]; i++)
        printf("Aliases %d: %s \n", i+1, host->h_aliases[i]);
    printf("Address type: %s \n", (host->h_addrtype==AF_INET)?"AF_INET":"AF_INET6");
    for (i = 0; host->h_addr_list[i]; i++)
        printf("IP addr %d: %s \n", i+1, inet_ntoa(*(struct in_addr*)&host->h_addr_list[i]));

    return 0;
}
