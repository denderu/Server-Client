#include <netinet/in.h>

#include <iostream>
#include <string>

#include "class_client.h"

using namespace std;

int main()
{
	int domain, type, protocol = 0;
	unsigned short int port; long int ipaddr;
	string message;
	cout<<"Welcome to Client program!"<<endl;
	//Создание клиента
	Client client;
	cout<<"Choose domain: 0-AF_UNIX      1-AF_INET"<<endl;
	cin>>domain;
	switch(domain)
	{
		case 0: domain = AF_UNIX; break;
		case 1: domain = AF_INET; break;
		default: break;
	};
	
	cout<<"Choose type: 0-SOCK_STREAM	1-SOCK_DGRAM	2-SOCK_RAW"<<endl;
	cin>>type;
	switch(type)
	{
		case 0: type = SOCK_STREAM; break;
		case 1: type = SOCK_DGRAM; break;
		case 2: type = SOCK_RAW; break;
		default: break;
	};
	client.CreateSocket(domain, type, protocol);
	
	//cout<<"Enter the IP address"<<endl;
	cout<<"Enter the number of port"<<endl;
	cin>>port;
	client.SetAddr(port, INADDR_LOOPBACK);
	client.Connect();
	
	//В главном цикле получаем сообщения с сервера и отдаем команды,
	//если это quit или no- выходим из программы
	do
	{
	  client.Receive();
	  cout<<client.GetBuffer()<<endl;
	  cin>>message;
	  client.Send(message.c_str());
	} while((message != "quit") && (message != "no"));

	return 0;
}