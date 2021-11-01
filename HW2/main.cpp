#include "mytar.h"
int main(int argc, char **argv)
{
    mytar tar((const char *)(argv[1]));
    tar.start_read();
    tar.print();
    return 0;
}