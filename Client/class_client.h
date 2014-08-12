#ifndef _CLIENT_H_
#define _CLIENT_H_
using namespace std;

class Client
{
	private:
		string buffer;
		int sock;
		struct sockaddr_in addr;
		char bufferChar[1024];
	public:
		Client();
		~Client();
		
		int CreateSocket(int domain, int type, int protocol);
		void SetAddr(unsigned short int port, long int addr);
		int Connect();
		int Send(const char* message);
		int Receive();
		string GetBuffer();
};
#endif