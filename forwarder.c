// forwarder.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fat.h>
#include <ogc/system.h>

int main(int argc, char **argv)
{
    if (fatInitDefault() < 0) {
        SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);
        return 0;
    }

    FILE *f = fopen("/boot/nextboot", "w");
    if (f) {
        fputs("linux\n", f);
        fclose(f);
        sync();
        sleep(1);
    }

    SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);
    return 0;
}
