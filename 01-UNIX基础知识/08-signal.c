#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096
static void sig_int(int);

/* {{{ 打断信号.ctrl+c 调用回调函数 ctrl+d退出 */
int main(void)
{
    char    buf[MAXLINE];
    pid_t   pid;
    int     status;
    
    if (signal(SIGINT, sig_int) == SIG_ERR) {
        printf("signal error");
        return -1;
    }

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0) {
            printf("fork error;\n");
            return -1;
        } else if (pid == 0) { // child
            execlp(buf, buf, (char *)0);
            printf("could't execute : %s \n", buf);
            return -1;
        }

        //parent
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            printf("waitpid error;\n");
        }

        printf("%% ");

    }

    return 0;
}
/* }}} */

/* {{{ signal 回调函数 void sig_int */
void sig_int(int signo)
{
    printf("interrupt\n%% ");
}
/* }}} */
