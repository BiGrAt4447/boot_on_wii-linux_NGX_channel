# gumboot startup pseudo script (POSIX shell style)
NEXTFLAG="/boot/nextboot"
if [ -f "$NEXTFLAG" ]; then
  val=$(cat "$NEXTFLAG" 2>/dev/null)
  if [ "$val" = "linux" ]; then
    rm -f "$NEXTFLAG"
    # Boot the Wii-Linux NGX entry (adjust to your bootloader command)
    boot_entry "Wii-Linux NGX"
    exit 0
  fi
fi

# otherwise show normal gumboot menu
show_gumboot_menu
