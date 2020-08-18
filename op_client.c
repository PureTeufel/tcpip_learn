/**********************************************************
 > File Name: op_client.c
 > Author: PureTeufel
 > Mail: PureTeufel@163.com
 > Created Time: Tue 18 Aug 2020 09:33:15 PM CST
**********************************************************/

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "err_handle.h"

#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4

int main(int argc, char** argv)
{
    int sock = 0;
    char opmsg[BUF_SIZE];
    int result, opnd_cnt, i;
    struct sockaddr_in serv_adr;
    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("connnect() error");
    else
        puts("Connected ......");

    fputs("Operand count: ", stdout);
    scanf("%d", &opnd_cnt);
    opmsg[0] = (char)opnd_cnt;

    for (i = 0; i < opnd_cnt; i++) {
        printf("Operand %d: ", i + 1);
        scanf("%d", (int*)&opmsg[i*OPSZ+1]);
    }
    fgetc(stdin);
    fputs("Operator: ", stdout);
    scanf("%c", &opmsg[opnd_cnt*OPSZ + 1]);
    write(sock, opmsg, opnd_cnt*OPSZ + 2);
    read(sock, &result, RLT_SIZE);

    printf("Operation result: %d \n", result);
    close(sock);
    
    return 0;
}