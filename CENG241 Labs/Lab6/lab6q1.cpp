#include <iostream>
#include <string>

using namespace std;

class UpDownNumbers{
	private:
		int start;
		int length;
		int* numbers;
		
	public:
		UpDownNumbers(int start, int len) : start{start}, length{len} {
			numbers = new int[length];
		}
		
		UpDownNumbers(const UpDownNumbers& old) : start{old.start}, length{old.length} {
			//cout << "Copy constructor has been called." << endl;
			
			numbers = new int[length];
			for(size_t i {0}; i < length; i++)
			{
				numbers[i] = old.numbers[i];
			}
		}
		
		~UpDownNumbers() {
			delete[] numbers;
		}
		
		void generate();
		void print();
		void setStart(int x);
		int getStart();
};

void UpDownNumbers::generate()
{
	numbers[0] = start;
	for(size_t i {0}; i < length - 1; i++)
	{
		if(numbers[i] % 2 == 0)
			numbers[i+1] = numbers[i] / 2 + 5;
			
		else
			numbers[i+1] = numbers[i] * 3 - 1;
	}
}

void UpDownNumbers::print()
{
	for(size_t i {0}; i < length; i++)
	{
		cout << numbers[i] << " ";
	}
	
	cout << endl;
}

void UpDownNumbers::setStart(int x)
{
	start = x;
}

int UpDownNumbers::getStart()
{
	return start;
}

int main()
{
	int start, len;
	
	cout << "Enter length and start for Object A: ";
	cin >> len;
	cin >> start;
	
	UpDownNumbers arr1(start, len);
	arr1.generate();
	UpDownNumbers arr2 = arr1;
	
	cout << "Object A (start: " + to_string(arr1.getStart()) + ", length: " + to_string(len) + "): ";
	arr1.print();
	cout << "Object B (b = a): ";
	arr2.print();
	
	cout << "Enter new start for Object B: ";
	cin >> start;
	arr2.setStart(start);
	arr2.generate();
	cout << "b.start is " + to_string(start) + " now" << endl;
	
	cout << "Object A (start: " + to_string(arr1.getStart()) + ", length: " + to_string(len) + "): ";
	arr1.print();
	cout << "Object A (start: " + to_string(arr2.getStart()) + ", length: " + to_string(len) + "): ";
	arr2.print();
	
	return 0;
}