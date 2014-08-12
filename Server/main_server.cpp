#include <netinet/in.h>

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
	persList.push_back(Person(++ID, "Novikov", "Egor", "8-921-777-2554"));
	//�������� ���� ���������
	while(1)
	{
	  message = "";
	  server.Send("Type 'quit' to exit the program");
	  read = server.Receive();
	  //���� ���������� �� ������� ������� add
	  if(server.GetBuffer() == "add")
	  {
		//�������� � ������� ���� ������ ������� Person
		server.Send("Enter the lastname:");
		  read = server.Receive();
		  perslname = server.GetBuffer();
		server.Send("Enter the firstname:");
		  read = server.Receive();
		  persfname = server.GetBuffer();
		server.Send("Enter the telephone number:");
		  read = server.Receive();
		  perspnumber = server.GetBuffer();
		  //������� ����� ������ Person � ��������� � ������
		  persList.push_back(Person(++ID, perslname, persfname, perspnumber));
		server.Send("Person was added. Do you want to continue? (yes/no)");
		  read = server.Receive();
		if(server.GetBuffer() == "no")  
		  break;
	  }
	  //���� ���������� �� ������� ������� find
	  else if(server.GetBuffer() == "find")
	  {
		//����������� ���� lastName �������� ������� Person
		server.Send("Enter the lastname:");
		read = server.Receive();
		iter = persList.begin(); 
		while(iter != persList.end())
		{
			//���� ���������� �������, �� ��������� ��������� �� �������
			if(iter->GetLastName() == server.GetBuffer())
			{
				message += iter->PersonInfo();
			}
			iter++;
		}
		//���� ����������� ��������� �����- ������ �� ������
		if(message == "")
		{	
			server.Send("Person was not found. Do you want to continue? (yes/no)");
			read = server.Receive();
			if(server.GetBuffer() == "no")  
				break;
		}
		//���� ��������� �� ������- ������� ��� (��� ���������� � ��������� ��������)
		else
		{
			message += "\nDo you want to continue? (yes/no)";
			server.Send(message.c_str());
			read = server.Receive();
			if(server.GetBuffer() == "no")  
				break;
		}
	  }
	  //���� ���������� �� ������� ������� show
	  else if(server.GetBuffer() == "show")
	  {
		iter = persList.begin(); 
		//��������� �� ������ � ��������� ��������� � ���� ��������
		while(iter != persList.end())
		{
			message += iter->PersonInfo();
			iter++;
		}
		message += "\nDo you want to continue? (yes/no)";
		server.Send(message.c_str());
		read = server.Receive();
		if(server.GetBuffer() == "no")  
			break;
	  }
	  //���� ���������� �� ������� ������� help
	  else if(server.GetBuffer() == "help")
	  {
		//�������� ������� ������ ��������� ������
		server.Send("List of commands:\nadd\nfind\nshow\n\nDo you want to continue? (yes/no)");
		read = server.Receive();
		if(server.GetBuffer() == "no")  
			break;
	  }
	  //���� ���������� �� ������� ������� �� �������
	  else 
	  {
		//
		message = "Command '"+server.GetBuffer()+"' not found\nDo you want to continue? (yes/no)";
		server.Send(message.c_str());
		read = server.Receive();
		if(server.GetBuffer() == "no")  
			break;
	  }
	} // ����� ��������� �����
	return 0;
} //����� main()

