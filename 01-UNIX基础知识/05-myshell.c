#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAXLINE 4096

/* {{{ 类似shell的基本实现,缺陷是不能解析参数 */
int main(void)
{
    char    buf[MAXLINE];
    pid_t   pid;
    int     status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        printf("%s\n", buf);
        if(buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0) {
            printf("fork error;\n");
            return -1;
        } else if (pid == 0) {  //child
            execlp(buf, buf, (char *)0);
            printf("couldn't execute: %s;\n", buf);
            return -1;
        }

        // parent
        if ((pid = waitpid (pid, &status, 0)) < 0) {
            printf("waitpid error;\n");
            return -1;
        }

        printf("%% ");
    }

    return 0;
}
/* }}} */
