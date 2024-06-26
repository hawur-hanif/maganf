import socket
from time import sleep

def get_ip():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.connect(("8.8.8.8", 80))
    _ip = s.getsockname()[0]
    s.close()
    return _ip


ip, port = get_ip(), 9999
serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


serverSock.bind((ip, port))
print("IP: ", ip, port)


while True:
    print("Nunggu client...")
    data, addr = serverSock.recvfrom(1024)
    data = str(data, encoding="latin-1")
    text = ""
    x = ""
    li = []
    for i in data:
        if i != " ":
            x += str(i)
        else:
            try:
                if int(float(x)) < 100:
                    text += "H "
                else:
                    text += "L "
                x = ""
            except:
                continue
    print(text)
    
    if data:
        _kirim = f"{text.strip()}\n".encode()
        serverSock.sendto(_kirim, addr)