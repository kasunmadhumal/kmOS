#include "frame_buffer.h"
#include "io.h"

static char *fb = (char *)FB_BASE_ADDRESS;
static unsigned short cursorPos = 0;


void fb_move_cursor(unsigned short pos) {
  outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
  outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
  outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
  outb(FB_DATA_PORT, pos & 0x00FF);
}

void fb_clear(unsigned short start, unsigned short end) {
  for (unsigned short i = start; i < end; i++) {
    fb[2 * i] = ' ';
    fb[2 * i + 1] = ((0 & 0x0F) << 4) | (15 & 0x0F);
  }
}


void fb_write_cell(char c, unsigned char fg, unsigned char bg) {
  if (c == '\n') {
    unsigned short cursorTempPos = cursorPos;
    cursorPos = ((cursorPos / 79) + 1) * 80;
    if (cursorPos >= 2000) {
      fb_clear(0, 2000);
      cursorPos = 0;
    } else {
      fb_clear(cursorTempPos, cursorPos);
    }
  } else if (c != '\0') {
    fb[2 * cursorPos] = c;
    fb[2 * cursorPos + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);

    cursorPos++;
    if (cursorPos >= 2000) {
      fb_clear(0, 2000);
      cursorPos = 0;
    }
  }
}

int fb_write(char *buf, unsigned int len) {
  unsigned int indexToBuffer = 0;
  while (indexToBuffer < len) {
    fb_write_cell(buf[indexToBuffer], FB_GREEN, FB_DARK_GREY);
    fb_move_cursor(indexToBuffer);
    indexToBuffer++;
  }
  return 0;
}
