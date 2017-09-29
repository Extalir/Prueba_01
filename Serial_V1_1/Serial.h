/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Serial.h
 * Author: str-har-pc
 *
 * Created on 25 de abril de 2016, 03:40 PM
 */

#ifndef SERIAL_H
#define SERIAL_H
#include <string>
#include <fcntl.h>			//Used for UART
#include <termios.h>	

using namespace std;

class Serial {
public:
    Serial();
    Serial(char *_port, int _baud);
    int Setup(char *_port, int _baud);
    int Send(unsigned char *p_tx_buffer);
    int Send(string tx_buffer);
    string Recive();
    Serial(const Serial& orig);
    virtual ~Serial();
private:
    int uart0_filestream = -1;
    char *port;
    int baud;
};

#endif /* SERIAL_H */

