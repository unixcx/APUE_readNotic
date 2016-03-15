#include <stdio.h>
#include <unistd.h>

/* {{{ 打印当前程序的进程ID */
int main(void)
{
    printf("hello 2016 from process ID %ld \n", (long)getpid());

    return 0;
}
/* }}} */
