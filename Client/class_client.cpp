#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "class_client.h"

using namespace std;

Client::Client()
{
  cout<<"Client object created"<<endl;
}

Client::~Client()
{
	close(sock);
}

int Client::CreateSocket(int domain, int type, int protocol)
{
	addr.sin_family = domain;
	sock = socket(domain, type, protocol);
	if(sock < 0)
	{
		perror("socket");
		exit(1);
	}
	else cout<<"Socket created"<<endl;
}

void Client::SetAddr(unsigned short int port, long int ipaddr)
{
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(ipaddr);
}

int Client::Connect()
{
	if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("Connection");
		exit(2);
	}
	else cout<<"Connection opened"<<endl;
}

int Client::Send(const char* message)
{
	send(sock, message, 100, 0);
}

int Client::Receive()
{
	recv(sock, bufferChar, 1024, 0);
	buffer = bufferChar;
}

string Client::GetBuffer()
{
  return buffer;
}