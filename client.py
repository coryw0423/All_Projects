# This project creates a client that can communicate with a server on the local host
# Name: Cory A Wilson
# BlazerID: coryw4
# Class: EE432
# Vers: 1.0.0 20200209 caw - Original Coding

import socket
import time

client = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
            # AF_INET = IP address
            # SOCK_STREAM = tcp oriented
address = (socket.gethostname(), 2020)
client.connect(address)
print('Type your message')
message = input()
byte_message = bytes(message, "utf-8")
client.send(byte_message)
time.sleep(1)
while True:
    time.sleep(10)
    data = client.recv(512)
    if (len(data) < 1):
        break
    print(data);

client.close()
