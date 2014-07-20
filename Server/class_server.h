#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Server
{
	public:
		int sock, listener;
		int bytes_read;
		struct sockaddr_in addr;
		char bufferChar[1024];
		string buffer;
		
		Server();
		~Server();
		
		int Listener(int domain, int type, int protocol);
		void SetAddr(unsigned short int port, long int addr);
		int Bind();
		void Start();
		friend int Send(Server& s, const char* message);
		friend int Receive(Server& s);
};