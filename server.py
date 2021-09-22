# This project creates a server, and send a message back to the client from the server
# Name: Cory A Wilson
# BlazerID: coryw4
# Class: EE432
# Vers: 1.0.0 20200209 caw - Original Coding


import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((socket.gethostname(), 2020))
server.listen(5)
print('Server awaiting connection')

while True:
    connection , address = server.accept()
    print('Connected!')
    data = server.recv(1024)
    data = data.decode()
    reply = data.upper()
    reply = bytes(reply , 'utf-8')
    server.send(reply)
    if not data:
        print('Error: No data!')
        server.close(connection, address)
        break







