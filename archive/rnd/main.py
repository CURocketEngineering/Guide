#!/usr/bin/env python
import serial

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=5)

line = '1'
while True:
	if line != 'end': 
	    	line = ser.readline().decode('utf-8').rstrip()
    		print(line)
	else:

		ser.write(b"Hello from Raspberry Pi\n")
		break
