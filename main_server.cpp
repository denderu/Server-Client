#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>

#include "class_server.h"
#include "class_person.h"

using namespace std;

int main()
{
	int domain, type, protocol = 0, read, ID = 0;
	string perslname, persfname, perspnumber;
	string message;
	unsigned short int port; long int ipaddr;
	
	cout<<"Welcome to Server program!"<<endl;
	Server server;
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
	server.Listener(domain, type, protocol);
	
	//cout<<"Enter the IP address"<<endl;
	cout<<"Enter the number of port"<<endl;
	cin>>port;
	server.SetAddr(port, INADDR_LOOPBACK);
	server.Bind();
	server.Start();
	cout<<"Client founded"<<endl;
	
	//������� ������ �������� Person
	list<Person> persList;
	list<Person>::iterator iter;
	persList.push_back(Person(++ID, "Ustimenko", "Denis", "8-923-244-0371"));
	persList.push_back(Person(++ID, "Nikitina", "Irina", "8-953-872-3772"));
	//�������� ���� ���������
	while(1)
	{
	  message = "";
	  Send(server, "Type 'quit' to exit the program");
	  read = Receive(server);
	  //���� ���������� �� ������� ������� add
	  if(server.buffer == "add")
	  {
		//�������� � ������� ���� ������ ������� Person
		Send(server, "Enter the lastname:");
		  read = Receive(server);
		  perslname = server.buffer;
		Send(server, "Enter the firstname:");
		  read = Receive(server);
		  persfname = server.buffer;
		Send(server, "Enter the telephone number:");
		  read = Receive(server);
		  perspnumber = server.buffer;
		  //������� ����� ������ Person � ��������� � ������
		  persList.push_back(Person(++ID, perslname, persfname, perspnumber));
		Send(server, "Person was added. Do you want to continue? (yes/no)");
		  read = Receive(server);
		if(server.buffer == "no")  
		  break;
	  }
	  //���� ���������� �� ������� ������� find
	  else if(server.buffer == "find")
	  {
		//����������� ���� lastName �������� ������� Person
		Send(server, "Enter the lastname:");
		read = Receive(server);
		iter = persList.begin(); 
		while(iter != persList.end())
		{
			//���� ���������� �������, �� ��������� ��������� �� �������
			if(iter->lastName == server.buffer)
			{
				message += iter->lastName + " " + iter->firstName + " " + iter->phoneNumber + "\n";
			}
			iter++;
		}
		//���� ����������� ��������� �����- ������ �� ������
		if(message == "")
		{	
			Send(server, "Person was not found. Do you want to continue? (yes/no)");
			read = Receive(server);
			if(server.buffer == "no")  
				break;
		}
		//���� ��������� �� ������- ������� ��� (��� ���������� � ��������� ��������)
		else
		{
			message += "\nDo you want to continue? (yes/no)";
			Send(server, message.c_str());
			read = Receive(server);
			if(server.buffer == "no")  
				break;
		}
	  }
	  //���� ���������� �� ������� ������� show
	  else if(server.buffer == "show")
	  {
		iter = persList.begin(); 
		//��������� �� ������ � ��������� ��������� � ���� ��������
		while(iter != persList.end())
		{
			message += iter->lastName + " " + iter->firstName + "\n";
			iter++;
		}
		message += "\nDo you want to continue? (yes/no)";
		Send(server, message.c_str());
		read = Receive(server);
		if(server.buffer == "no")  
			break;
	  }
	  //���� ���������� �� ������� ������� help
	  else if(server.buffer == "help")
	  {
		//�������� ������� ������ ��������� ������
		Send(server, "List of commands:\nadd\nfind\nshow\n\nDo you want to continue? (yes/no)");
		read = Receive(server);
		if(server.buffer == "no")  
			break;
	  }
	  //���� ���������� �� ������� ������� �� �������
	  else 
	  {
		//
		message = "Command '"+server.buffer+"' not found\nDo you want to continue? (yes/no)";
		Send(server, message.c_str());
		read = Receive(server);
		if(server.buffer == "no")  
			break;
	  }
	} // ����� ��������� �����
	return 0;
} //����� main()

