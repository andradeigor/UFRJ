import socket

HOST = '177.195.104.248'     # Endereco IP do Servidor
PORT = 5300            # Porta que o Servidor esta
dest = (HOST, PORT)

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp.connect(dest)

msg = input("Digite uma mensagem: ")

while msg != '':
    tcp.send(msg.encode('utf-8'))
    ret = tcp.recv(1024)
    print(str(ret, encoding='utf-8'))
    msg = input("Digite uma mensagem: ")

tcp.close()