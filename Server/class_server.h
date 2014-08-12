#ifndef _SERVER_H_
#define _SERVER_H_
<<<<<<< HEAD

#include <iostream>
#include <fstream>
=======
>>>>>>> 5b0dff6f5d2969f4edce52b938f030b35cc0c137
using namespace std;

class Server
{
	private:
		int sock, listener;
		struct sockaddr_in addr;
		char bufferChar[1024];
		string buffer;
<<<<<<< HEAD
		ofstream fileLogger;
=======
>>>>>>> 5b0dff6f5d2969f4edce52b938f030b35cc0c137
	public:
		Server();
		~Server();
		int Listener(int domain, int type, int protocol);
		void SetAddr(unsigned short int port, long int addr);
		int Bind();
		void Start();
		int Send(const char* message);
		int Receive();
		string GetBuffer();
};
#endif