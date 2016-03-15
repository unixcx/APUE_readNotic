#include <stdio.h>
#include <errno.h>
#include <string.h>

/* {{{ strerror && perror 函数用法 */
int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT; 
    perror(argv[0]);

    return 0;
}
/* }}} */
