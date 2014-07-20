using namespace std;

class Person
{
	public:
	string lastName;
	string firstName;
	string phoneNumber;
	int ID;

	public:
	Person();
	Person(int id, string lname, string fname, string pnumber);
	void display() const; 
	string get_phone() const; 
	
	friend bool operator<(Person&, Person&);
	friend bool operator==(Person&, Person&);
};