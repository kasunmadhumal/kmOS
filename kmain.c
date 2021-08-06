#include "frame_buffer.h"
#include "serial_port.h"



/* The C function */
int sum_of_three(int a, int b, int c) {
  char buffer[15] = "Welcome to kmOS";
  fb_write(buffer, 16);
  serial_configure(SERIAL_COM1_BASE, Baud_115200);
  serial_write(SERIAL_COM1_BASE, buffer, 16);
  return a + b + c;
}

