/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Serial.cpp
 * Author: str-har-pc
 * 
 * Created on 25 de abril de 2016, 03:40 PM
 */

#include "Serial.h"

Serial::Serial() {
    uart0_filestream=-1;
    baud=0;
}

Serial::Serial(char* _port, int _baud)
{
    Setup(_port,_baud);
}

int Serial::Setup(char* _port, int _baud)
{
    port=_port;
    uart0_filestream = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    if (uart0_filestream == -1)
    {
        cout<<"Error - Unable to open UART.  Ensure it is not in use by another application \r\n";
        close(uart0_filestream);
        return -1;
    }
    
    switch(_baud)
    {
        case 1200:
            baud=B1200;
            break;
        case 2400:
            baud=B2400;
            break;
        case 4800:
            baud=B4800;
            break;
        case 9600:
            baud=B9600;
            break;
        case 19200:
            baud=B19200;
            break;
        case 38400:
            baud=B38400;
            break;
        case 57600:
            baud=B57600;
            break;
        case 115200:
            baud=B115200;
            break;
        case 230400:
            baud=B230400;
            break;
    }
    struct termios options;
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = baud | CS8 | CLOCAL | CREAD;		//<Set baud rate
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);
    
    return 0;
}

Serial::Recive()
{
}

Serial::Send(unsigned char* p_tx_buffer)
{
    unsigned char tx_buffer[20];
    p_tx_buffer = &tx_buffer[0];
    if (uart0_filestream != -1)
    {
        int count = write(uart0_filestream, p_tx_buffer, sizeof(p_tx_buffer));		//Filestream, bytes to write, number of bytes to write
        if (count < 0)
        {
            cout<<"UART TX error\r\n";
            return -1;
        }
    }
    return 0;
}

Serial::Send(string tx_buffer)
{
}

Serial::Serial(const Serial& orig) {
}

Serial::~Serial() {
}

