#include "drivers/frame_buffer/frame_buffer.h"
#include "drivers/serial_port/serial_port.h"
#include "Segmentation/gdt.h"






void init() {
 
  init_gdt();

  
  serial_configure(SERIAL_COM1_BASE, Baud_115200);
}


int kmain() {
  init();
  char buffer[20] = "Welcome to kmOS\n";
  fb_write(buffer, 20);
  serial_write(SERIAL_COM1_BASE, buffer, 20);
  return 0;
}
