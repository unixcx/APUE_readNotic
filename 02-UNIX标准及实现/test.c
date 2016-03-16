#include <stdio.h>
#include <unistd.h>

static void conf_dump(int);

int main(int argc, char *argv[])
{
    int name;
//    if (argc != 2) {
//        printf("param num error!\n");
//        return 0;
//    }

    name = _SC_ARG_MAX;
    conf_dump(name);

    return 0;
}

void conf_dump(int name)
{
    printf("conf marco _SC_ARG_MAX %d value is : %ld;\n", name, sysconf(name));
}
