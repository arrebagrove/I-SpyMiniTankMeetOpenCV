
#include "stdafx.h"

#include <stdio.h>
#include <WinSock2.h>
#include "SpyMini.h"
#pragma comment(lib, "ws2_32.lib")

#define FORWARD "1121"
#define BACKWARD "1222"
#define STOP "1020"
#define TURNLEFT "1122"
#define TURNRIGHT "1221"


SpyMini::SpyMini(){
	
}


void SpyMini::connectToTank(){
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return;
	}
	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr("10.10.1.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8150);
	//Connect to remote server
	if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return;
	}
	puts("Connected");
	setSocket(s);
	
}
void SpyMini::setSocket(SOCKET s){
	sock = s;
}
SOCKET SpyMini::getSocket(){
	return sock;
}
void SpyMini::setMsg(char *message){
	msg = message;
}
char* SpyMini::getMsg(){
	return msg;
}
void SpyMini::moveIt(){
	SOCKET s= getSocket();
	char *message;
	message = getMsg();

	if (send(s, message, strlen(message), 0) < 0)
	{
		puts("Send failed");
		return;
	}
	puts("Data Send\n");

}

void SpyMini::forward(){
	setMsg(FORWARD);
	moveIt();
}

void SpyMini::backward(){
	setMsg(BACKWARD);
	moveIt();

}

void SpyMini::turnLeft(){
	setMsg(TURNLEFT);
	moveIt();
}

void SpyMini::turnRigt(){
	setMsg(TURNRIGHT);
	moveIt();
}

void SpyMini::stop(){
	setMsg(STOP);
	moveIt();
}