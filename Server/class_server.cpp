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
<<<<<<< HEAD
	cout<<"Server object created"<<endl;
=======
  cout<<"Server object created"<<endl;
>>>>>>> 5b0dff6f5d2969f4edce52b938f030b35cc0c137
}

Server::~Server()
{
	close(sock);
<<<<<<< HEAD
	fileLogger.close();
=======
>>>>>>> 5b0dff6f5d2969f4edce52b938f030b35cc0c137
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
<<<<<<< HEAD
	
	fileLogger.open("/home/denis/work/Server-Client/log.txt", ios::out);
=======
>>>>>>> 5b0dff6f5d2969f4edce52b938f030b35cc0c137
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
<<<<<<< HEAD
	fileLogger<<"Server started"<<endl;
=======
>>>>>>> 5b0dff6f5d2969f4edce52b938f030b35cc0c137
}

int Server::Send(const char* message)
{
	send(sock, message, 100, 0);
<<<<<<< HEAD
	fileLogger<<"Server: "<<message<<endl;
=======
>>>>>>> 5b0dff6f5d2969f4edce52b938f030b35cc0c137
}

int Server::Receive()
{
	recv(sock, bufferChar, 1024, 0);
	buffer = bufferChar;
<<<<<<< HEAD
	fileLogger<<"Client: "<<buffer<<endl;
=======
>>>>>>> 5b0dff6f5d2969f4edce52b938f030b35cc0c137
}

string Server::GetBuffer()
{
  return buffer;
}