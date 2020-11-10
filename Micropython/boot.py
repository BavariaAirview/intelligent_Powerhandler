# Complete project details at https://RandomNerdTutorials.com

try:
  import usocket as socket
except:
  import socket

from machine import Pin
import network

from time import sleepms
import esp
esp.osdebug(None)

ssid = 'Kellerkind'
password = 'Syn2tony'

station = network.WLAN(network.STA_IF)

station.active(True)
station.connect(ssid, password)

while station.isconnected() == False:
  pass

import webrepl
webrepl.start()

#print('Connection successful')
#print(station.ifconfig())