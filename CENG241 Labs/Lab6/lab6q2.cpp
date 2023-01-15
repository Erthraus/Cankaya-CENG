#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class NumbersClass{
	private:
		int* numbers;
		int length;
		bool isPrime(int x);
		
	public:
		NumbersClass() : length{5} {
			//cout << "Default constructor has been called." << endl;
			numbers = new int[length];
		}
		
		NumbersClass(int n) : length{n} {
			//cout << "Overloaded constructor has been called." << endl;
			numbers = new int[length];
		}
		
		NumbersClass(const NumbersClass& old) : length{old.length} {
			//cout << "Copy constructor has been called." << endl;
			
			numbers = new int[length];
			for(size_t i {0}; i < length; i++)
			{
				numbers[i] = old.numbers[i];
			}
		}
		
		~NumbersClass() {
			delete[] numbers;
		}
		
		void generate();
		void filter(string choice);
		void print();
};

void NumbersClass::generate()
{
	for(size_t i {0}; i < length; i++)
	{
		numbers[i] = rand() % 10000;
	}
}

void NumbersClass::filter(string choice)
{
	if(choice == "nonprime")
	{
		for(size_t i {0}; i < length; i++)
		{
			if(isPrime(numbers[i]))
				numbers[i] = -1;
		}
	}
	
	else if(choice == "prime")
	{
		for(size_t i {0}; i < length; i++)
		{
			if(!isPrime(numbers[i]))
				numbers[i] = -1;
		}
	}
}

bool NumbersClass::isPrime(int x)
{
	if(x < 2)
		return false;
		
	else if(x == 2)
		return true;
		
	else
	{
		for(size_t i {2}; i <= x / 2; i++)
		{
			if(x % i == 0)
				return false;
		}
	}
	
	return true;
}

void NumbersClass::print()
{
	for(size_t i {0}; i < length; i++)
	{
		if(numbers[i] != -1)
			cout << numbers[i] << " ";
	}
	
	cout << endl;
}

int main()
{
	srand(time(0));
	int len;
	cout << "Enter length: ";
	cin >> len;
	
	NumbersClass arr1(len);
	arr1.generate();
	
	NumbersClass arr2 = arr1;
	NumbersClass arr3 = arr1;
	
	arr2.filter("prime");
	arr3.filter("nonprime");
	
	cout << "A: ";
	arr1.print();
	cout << "B: ";
	arr2.print();
	cout << "C: ";
	arr3.print();
	
	return 0;
}