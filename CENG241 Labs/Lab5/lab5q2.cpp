#include <iostream>
#include <string>
#include <iomanip>

#define N 5

using namespace std;

class Contact {
	private:
		string name;
		string number;
		
	public:
		Contact() : name{"Unknown"}, number{"0"} {
			
		}
		
		Contact(string name, string num) : name{name}, number{num} {
			
		}
		
		void print(string x);
		
		void set_name(string name);
		string get_name();
		
		void set_number(string num);
		string get_number();
};

class AdressBook {
	private:
		void rearrange();
		int search(string x);
		int nrofcontacts {0};
		Contact contacts[N];
		
	public:
		AdressBook() {
			
		}
		
		bool add(Contact x);
		bool remove(string x);
		void print();
};

void Contact::print(string x)
{
	if(x == "light")
	{
		cout << left << setw(10) << name << number << endl;
	}
	
	else if(x == "headers")
	{
		cout << left << "Name: " << setw(10) << name << "Number: " << number << endl;
	}
	
	else
	{
		cout << "ERROR" << endl;
	}
}

void Contact::set_name(string name)
{
	this->name = name;
}

string Contact::get_name()
{
	return name;
}

void Contact::set_number(string num)
{
	this->number = num;
}

string Contact::get_number()
{
	return number;
}

int AdressBook::search(string x)
{
	for(int i {0}; i < nrofcontacts; i++)
	{
		if(x == contacts[i].get_name())
			return i;	
	}
	
	return -1;
}

bool AdressBook::add(Contact x)
{
	if(N <= nrofcontacts)
	{
		cout << "AdressBook is full." << endl;
		return false;
	}
	
	else if(search(x.get_name()) == -1)
	{
		contacts[nrofcontacts] = x;
		nrofcontacts++;
		return true;
	}
	
	else
		return false;
}

bool AdressBook::remove(string x)
{
	int loc = search(x);
	if(loc == -1)
		return false;
		
	else
	{
		contacts[loc].set_name("Unknown");
		contacts[loc].set_number("0");
		rearrange();
		nrofcontacts--;
		return true;
	}
}

void AdressBook::rearrange()
{
	for(int i {0}; i < N-1; i++)
	{
		if(contacts[i].get_name() == "Unknown" && contacts[i+1].get_name() != "Unknown")
		{
			contacts[i] = contacts[i+1];
			contacts[i+1].set_name("Unknown");
			contacts[i+1].set_number("0");
		}
	}
}

void AdressBook::print()
{
	if(nrofcontacts == 0)
		cout << "No contacts available." << endl;
	
	else 
	{
		cout << left << setw(10) << "Name" << "Number" << endl;
		
		for(int i {0}; i < nrofcontacts; i++)
			contacts[i].print("light");   // headers	
	}
}

int main()
{
	Contact c;
	AdressBook aBook;
	int flag {1}, ch;
	string temp;
	
	do{
		cout << endl << "1. Display Address Book";
		cout << endl << "2. Add New Contact";
		cout << endl << "3. Remove Contact";
		cout << endl << "4. Exit";
		cout << endl << "Enter your choice: ";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				aBook.print();
				break;
			
			case 2:
				cout << "Enter name: ";
				cin >> temp;
				c.set_name(temp);
				cout << "Enter number: ";
				cin >> temp;
				c.set_number(temp);
				
				if(aBook.add(c) == true)
					cout << "Contact added." << endl;
					
				else
					cout << "Contact already exists." << endl;
					
				break;
				
			case 3:
				cout << "Enter name: ";
				cin >> temp;
				
				if(aBook.remove(temp) == true)
					cout << "Contact removed." << endl;
					
				else
					cout << "Contact is not available." << endl;
					
				break;
				
			case 4:
				flag = 0;
				cout << "Goodbye.";
				break;
				
			default:
				cout << "Wrong input. Try again." << endl;
				break;
		}
	}while(flag);
	
	return 0;
}