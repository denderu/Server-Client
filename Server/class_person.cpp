#include <iostream>
#include <string>

#include "class_person.h"

using namespace std;

Person::Person() : ID(0), lastName("n/a"), firstName("n/a"), phoneNumber("n/a")
{ }

Person::Person(int id, string lname, string fname, string pnumber) : ID(id), lastName(lname), firstName(fname), phoneNumber(pnumber)
{ }

string Person::PersonInfo()
{
	return (lastName + " " + firstName + " " + phoneNumber + "\n");
}

string Person::GetLastName()
{
	return lastName;
}

bool operator==(Person& p1, Person& p2)
{
	return (p1.lastName == p2.lastName && p1.firstName == p2.firstName) ? true : false;
}

bool operator<(Person& p1, Person& p2)
{
	if(p1.lastName == p2.lastName)
	return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}
