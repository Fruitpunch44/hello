#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

typedef struct{
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
}Sockaddr_in_server_adresss;

int main()
{
Sockaddr_in_server_adresss client;
char buffer[1024]="hello from client";
char recv_buffer[1024];
WSADATA wsaData;
if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
    printf("WSAStartup() failed\n");
    return 1;
}
int client_socket =socket(AF_INET, SOCK_STREAM, 0);
client.sin_family = AF_INET;
client.sin_port=htons(90001);
client.sin_addr.s_addr = inet_addr("192.168.0.139");

connect(client_socket, (struct sockaddr *)&client, sizeof(client)); 
recv(client_socket,recv_buffer,sizeof(recv_buffer),0);
printf("data from the server %s\n",recv_buffer);
send(client_socket,buffer,sizeof(buffer),0);
closesocket(client_socket);
WSACleanup();
  return 0;
}
 