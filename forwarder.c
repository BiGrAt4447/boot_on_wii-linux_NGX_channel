// forwarder.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fat.h>
#include <ogc/system.h>
#include <ogc/machine/processor.h>

int main(int argc, char **argv)
{
    // Try to mount FAT (default libfat mount)
    if (fatInitDefault() < 0) {
        // If FAT init fails, return to system menu
        SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);
        return 0;
    }

    // Attempt to write the nextboot flag
    FILE *f = fopen("/boot/nextboot", "w");
    if (f) {
        fputs("linux\n", f);
        fclose(f);
        sync();        // flush filesystem buffers
        sleep(1);      // ensure write completes
    }

    // Option A: return to Wii Menu so Gumboot runs on next boot
    SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);

    // Option B (alternative): attempt immediate restart (uncomment if desired)
    // SYS_ResetSystem(SYS_RESTART, 0, 0);

    return 0;
}
