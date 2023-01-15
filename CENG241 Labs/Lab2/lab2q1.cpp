#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
	string file_name, line;
	char answ;
	
	cout << "Enter file name: ";
	cin >> file_name;
	cin.ignore();
	
	fstream file;
	file.open(file_name + ".txt", ios::in | ios::out | ios::trunc);
	
	if(!file) 
	{
		cout << "File creation failed";
		return 0;
	}
		
	cout << "Enter information to store:" << endl;
	do{	
		getline(cin, line);
		file << line << endl;
		while(1)
		{
			cout << "Want to enter more? (y/n): ";
			cin >> answ;
			cin.ignore();
			
			if(answ == 'y' || answ == 'n')
				break;
				
			else
				cout << "You have entered a wrong answer!" << endl;
		}
		
			
	}while(answ == 'y');

	cout << "The information successfully stored in the file!" << endl;
	while(1)
	{
		cout << "\nWant to See? (y/n): ";
		cin >> answ;
		
		if(answ == 'y' || answ == 'n')
			break;
				
		else
			cout << "You have entered a wrong answer!" << endl;
	}
	
	file.seekg(0);
	
	if(answ == 'y')
	{
		cout << "The file contains:" <<  endl;
		while(getline(file, line))
		{
			cout << line << endl;
		}
		
	}
	
	file.close();
	return 0;
}