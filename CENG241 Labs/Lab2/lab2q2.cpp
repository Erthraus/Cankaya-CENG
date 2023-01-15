#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string line, sub;
	size_t pos;
	
	cout << "Enter a string: ";
	getline(cin, line);
	
	cout << "Enter substring you want to search: ";
	cin >> sub;
	
	if((pos = line.find(sub)) != string::npos)
		cout << "The substring [" + sub + "] is present in given string at position [" << pos << "]";
	
	else
		cout << "There is no " << sub << " in this string.";
	
	return 0;
}