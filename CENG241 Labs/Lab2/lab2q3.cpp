#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string line;
	int vowels = 0, consonants = 0, digits = 0, white_spaces = 0; 
	
	cout << "Enter a line of string: ";
	getline(cin, line);
	
	for(int i = 0; i < line.length(); i++)
	{
		if(line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U' || 
		   line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u')
			vowels++;
		
		else if(line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z')
			consonants++;
			
		else if(line[i] == ' ')
			white_spaces++;
			
		else if(line[i] >= '0' && line[i] <= '9')
			digits++;
	}
	
	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "White Spaces " << white_spaces;
	
	return 0;
}