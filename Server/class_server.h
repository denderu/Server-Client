#ifndef _SERVER_H_
#define _SERVER_H_
using namespace std;

class Server
{
	private:
		int sock, listener;
		struct sockaddr_in addr;
		char bufferChar[1024];
		string buffer;
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