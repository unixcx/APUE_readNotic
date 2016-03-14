// 此文件开始还没有自己的风格.
// 算是刚开始学习C语言吧.
// 毕竟又是一个轮回.
// 希望很久之后这个仓库能见证自己的历程,看到自己的成长.
// 2016-03-14 啊哦~白色情人节?

#include <dirent.h>
#include <stdio.h>

/* {{{ 实例1-3  ls命令简要实现. in page 4;*/
int main(int argc, char *argv[])
{
    DIR              *dp;
    struct dirent    *dirp;

    if (argc != 2) {
        printf("argc != 2;\n");
        return -1;
    }

    if ((dp = opendir(argv[1])) == NULL) {
        printf("%s :: can't be opened!\n", argv[1]);
        return -1;
    }

    while ((dirp = readdir(dp)) != NULL) {
//        if (dirp->d_name[0] != '.')
        printf("%s\n", dirp->d_name);
    }

    return 0;
}
/* }}} */
