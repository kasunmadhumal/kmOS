#include "src/segmentation/gdt.h"
#include "src/drivers/interrupts/idt.h"
#include "src/utils/logger/logger.h"
#include "src/drivers/serial_port/serial_port.h"
#include "src/drivers/timer/timer.h"
#include "src/utils/common/types.h"
#include "multiboot.h"

/* Function to initialize */
void init(u32int kernelPhysicalStart, u32int kernelPhysicalEnd,u32int kernel_virtual_end ,u32int kernel_virtual_start) {
  /* Initialize segment descriptor tables */
  init_gdt();

  /* Initialize segment descriptor tables */
  init_idt();

  /* Initialize timer interrupt */
//  init_timer(TIMER_FREQUENCY);

  /* Initialize display */
  init_display();

  /* Configure serial port */
  serial_configure(SERIAL_COM1_BASE, Baud_115200);

  /* Initialize paging */
  init_paging(kernelPhysicalStart, kernelPhysicalEnd ,kernel_virtual_end ,kernel_virtual_start);

  /* Initialize keyboard */
  init_keyboard();
}


s32int kmain(u32int kernelPhysicalStart, u32int kernelPhysicalEnd,u32int kernel_virtual_end ,u32int kernel_virtual_start) {

  init(kernelPhysicalStart, kernelPhysicalEnd,kernel_virtual_end ,kernel_virtual_start);

 
  run_all_tests();

  return 0;
}
