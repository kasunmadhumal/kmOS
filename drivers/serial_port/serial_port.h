#ifndef INCLUDE_SERIALPORT_H
#define INCLUDE_SERIALPORT_H

#pragma once




#define SERIAL_COM1_BASE 0x3F8 

#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base) (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base) (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base) (base + 5)


enum BaudRate { Baud_115200 = 1, Baud_57600, Baud_19200, Baud_9600 };


#define SERIAL_LINE_ENABLE_DLAB 0x80


void serial_configure_baud_rate(unsigned short com, unsigned short divisor);


void serial_configure_line(unsigned short com);


void serial_configure_fifo_buffer(unsigned short com);


void serial_configure_modem(unsigned short com);


int serial_is_transmit_fifo_empty(unsigned short com);


int serial_write(unsigned short com, char *buf, unsigned int len);


void serial_write_byte(unsigned short port, char byteData);


void serial_configure(unsigned short port, unsigned short baudRate);

#endif 
