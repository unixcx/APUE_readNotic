#include <stdio.h>
#include <unistd.h> // declared getuid/getgid

int main(void)
{
    printf("uid = %d, gid = %d.\n", getuid(), getgid());

    return 0;
}
