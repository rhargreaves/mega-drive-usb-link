#!/usr/bin/env python 
import serial

port = "/dev/cu.usbserial-A105J2JO"
ser = serial.Serial(
        port, 
        baudrate=57600,
        timeout=None,
        bytesize=8,
        parity='N',
        stopbits=1)
for i in range(1024):
    ser.write('0' * 1024)
ser.close()

