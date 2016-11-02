#!/usr/bin/env python

# Standard Library Imports
from __future__ import print_function
import time
import argparse

# External Packages
import serial

# Local Imports
import settings


import argparse

parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('-c','--char', type=str, default='A',  help='single string to send through loopback')
args = parser.parse_args()
if len(args.char) > 1:
    raise Exception("Single character required for 'char' input")

with serial.Serial(settings.port, settings.baud, timeout=2) as serial_port:
    serial_port.flush()
    
    message = args.char
    print("TX: " + message)
    serial_port.write(message)
    while serial_port.inWaiting() == 0:
        time.sleep(0.05)
        print(serial_port.inWaiting())
    received = serial_port.read(serial_port.inWaiting())
    print("RX: " + received)
    
    
