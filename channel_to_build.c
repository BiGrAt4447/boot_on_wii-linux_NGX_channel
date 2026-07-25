// forwarder.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fat.h>
#include <ogc/system.h>

int main(int argc, char **argv)
{
    // Initialize FAT (mounts the FAT partition)
    if (fatInitDefault() < 0) {
        // If FAT init fails, return to menu
        SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);
        return 0;
    }

    // Write the nextboot flag
    FILE *f = fopen("/boot/nextboot", "w");
    if (f) {
        fputs("linux\n", f);
        fclose(f);
        // Ensure data is flushed to disk
        sync();
        sleep(1);
    }

    // Return to Wii Menu so Gumboot (or bootloader) can run on next boot
    SYS_ResetSystem(SYS_RETURNTOMENU, 0, 0);

    // Alternative: try to reboot immediately
    // SYS_ResetSystem(SYS_RESTART, 0, 0);

    return 0;
}
