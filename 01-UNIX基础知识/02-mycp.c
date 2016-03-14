#include <stdio.h>
#include <unistd.h> //STDIN_FILENO && STDOUT_FILENO && read() && write()

#define BUFFSIZE    4096
/* {{{ in page 7. 复制任一unix普通文件. 用法 ./a.out < 源文件 > 输出文件; eg: ./a.out < 02-mycp.c > 02-mycp_bak.c */
int main(void)
{
    int     n;
    char    buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            printf("write error;\n");
            return -1;
        }
    }

    if (n < 0) {
        printf("read error;\n");
        return -1;
    }

    return 0;
}
/* }}} */
