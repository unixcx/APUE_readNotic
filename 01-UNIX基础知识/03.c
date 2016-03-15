#include <stdio.h>

/* {{{ page 9. 图1-5 将标准输入复制到标准输出. */
int main(void)
{
    int     c;
    while ((c = getc(stdin)) != EOF){
        if (putc(c, stdout) == EOF) {
            printf("output error");
            return -1;
        }
    }

    if (ferror(stdin)) {
        printf("input error");
        return -1;
    }

    return 0;
}
/* }}} */
