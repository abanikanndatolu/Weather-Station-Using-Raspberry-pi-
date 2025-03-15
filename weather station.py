import socket

server_ip = "ESP32_IP"
port = 80

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((server_ip, port))

while True:
    data = client_socket.recv(1024).decode()
    if data:
        print("Weather Data: ", data)
