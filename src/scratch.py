import time

import bluetooth

bd_addr = "98:D3:31:FC:1A:4E"

port = 1

sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)

sock.connect((bd_addr, port))

sock.send("1")

time.sleep(5)
sock.send("0")
sock.close()

# 32768