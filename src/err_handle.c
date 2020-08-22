/**********************************************************
 > File Name: err_handle.c
 > Author: PureTeufel
 > Mail: PureTeufel@163.com
 > Created Time: Tue 18 Aug 2020 10:02:07 PM CST
**********************************************************/

#include "err_handle.h"

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    _exit(1);
}
