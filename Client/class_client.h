using namespace std;

class Client
{
	public:
		int sock;
		char bufferChar[1024];
		string buffer;
		struct sockaddr_in addr;
		
		Client();
		~Client();
		
		int CreateSocket(int domain, int type, int protocol);
		void SetAddr(unsigned short int port, long int addr);
		int Connect();
		friend int Send(Client& c, const char* message);
		friend int Receive(Client& c);
};