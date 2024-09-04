import socket

HOST = '127.0.0.1'              # Endereco IP do Servidor
PORT = 5300            # Porta que o Servidor esta

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

orig = (HOST, PORT)

udp.bind(orig)

while True:
    message, clientAddress = udp.recvfrom(2048)
    print(message, clientAddress)
    modifiedMessage = message.upper()
    udp.sendto(modifiedMessage, clientAddress)

udp.close()