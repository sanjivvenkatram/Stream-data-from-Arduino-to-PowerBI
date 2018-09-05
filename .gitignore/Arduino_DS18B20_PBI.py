## import respective libraries

import serial
import time
import requests
from datetime import datetime

## note the right COM port below!!

ser = serial.Serial('COM3', baudrate = 9600)

REST_API_URL = "enter your API key here, keep the quotes"

while 1:
    t = ser.readline().rstrip()
    t = float(t.decode())
    #print (t)
    
    now=datetime.strftime(datetime.now(), "%Y-%m-%dT%H:%M:%S%Z")
    #print (now)

    data = '[{{"timestamp":"{0}","temperature":"{1:0.1f}"}}]'.format(now,t)
    print (data)
    req = requests.post(REST_API_URL,data)
    time.sleep(0)

