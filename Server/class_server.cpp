#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "class_server.h"

using namespace std;

Server::Server()
{
	cout<<"Server object created"<<endl;
}

Server::~Server()
{
	close(sock);
	fileLogger.close();
}

int Server::Listener(int domain, int type, int protocol)
{
	addr.sin_family = domain;
	listener = socket(domain, type, protocol);
	if(listener < 0)
	{
		perror("Socket");
		exit(1);
	}
	else cout<<"Socket created"<<endl;
}

void Server::SetAddr(unsigned short int port, long int ipaddr)
{
	//addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(ipaddr);
}

int Server::Bind()
{
	if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("Bind");
		exit(2);
	}
	else cout<<"Binding completed"<<endl;
	
	fileLogger.open("/home/denis/work/Server-Client/log.txt", ios::out);
}

void Server::Start()
{
	listen(listener, 1);
  
	cout<<"Listening..."<<endl;
	sock = accept(listener, NULL, NULL);
	if(sock < 0)
	{
		perror("accept");
		exit(3);
	}
	fileLogger<<"Server started"<<endl;
}

int Server::Send(const char* message)
{
	send(sock, message, 100, 0);
	fileLogger<<"Server: "<<message<<endl;
}

int Server::Receive()
{
	recv(sock, bufferChar, 1024, 0);
	buffer = bufferChar;
	fileLogger<<"Client: "<<buffer<<endl;
}

string Server::GetBuffer()
{
  return buffer;
}