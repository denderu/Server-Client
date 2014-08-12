#ifndef _PERSON_H_
#define _PERSON_H_
using namespace std;

class Person
{
	private:
	string lastName;
	string firstName;
	string phoneNumber;
	int ID;

	public:
	Person();
	Person(int id, string lname, string fname, string pnumber);
	string PersonInfo(); 
	string GetLastName();
	
	friend bool operator<(Person&, Person&);
	friend bool operator==(Person&, Person&);
};
#endif