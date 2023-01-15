#include <iostream>
#include <string>

using namespace std;

class calculator
{
private:
	float *numbers;
	int length;

public:
	calculator() : length{4}, numbers{nullptr}
	{
		// cout << "Constructor has been called" << endl;
		numbers = new float[length];
	}

	calculator(int n) : length{n}, numbers{nullptr}
	{
		// cout << "Overloaded constructor has been called" << endl;
		numbers = new float[length];
	}

	~calculator()
	{
		//cout << "Destructor has been called" << endl;
		delete[] numbers;
	}

	calculator operator+(const calculator &obj);
	calculator operator-(const calculator &obj);
	calculator operator*(const calculator &obj);
	calculator operator/(const calculator &obj);
	calculator &operator=(const calculator &obj);

	friend ostream &operator<<(ostream &os, const calculator &obj);

	void setNumber(float num, int n);
};

calculator calculator::operator+(const calculator &obj)
{
	int len;
	if(length < obj.length)
		len = length;
	else
		len = obj.length;

	calculator temp(len);

	for (int i{0}; i < temp.length; i++)
	{
		temp.numbers[i] = numbers[i] + obj.numbers[i];
	}

	return temp;
}

calculator calculator::operator-(const calculator &obj)
{
	int len;
	if(length < obj.length)
		len = length;
	else
		len = obj.length;

	calculator temp(len);

	for (int i{0}; i < temp.length; i++)
	{
		temp.numbers[i] = numbers[i] - obj.numbers[i];
	}

	return temp;
}

calculator calculator::operator*(const calculator &obj)
{
	int len;
	if(length < obj.length)
		len = length;
	else
		len = obj.length;

	calculator temp(len);

	for (int i{0}; i < temp.length; i++)
	{
		temp.numbers[i] = numbers[i] * obj.numbers[i];
	}

	return temp;
}

calculator calculator::operator/(const calculator &obj)
{
	int len;
	if(length < obj.length)
		len = length;
	else
		len = obj.length;

	calculator temp(len);

	for (int i{0}; i < temp.length; i++)
	{
		temp.numbers[i] = numbers[i] / obj.numbers[i];
	}

	return temp;
}

calculator &calculator::operator=(const calculator &obj)
{
	length = obj.length;

	for (int i{0}; i < length; i++)
	{
		numbers[i] = obj.numbers[i];
	}

	return *this;
}

ostream &operator<<(ostream &os, const calculator &obj)
{
	for (int i{0}; i < obj.length; i++)
	{
		os << obj.numbers[i] << " ";
	}

	return os;
}

void calculator::setNumber(float num, int n)
{
	numbers[n] = num;
}

int main()
{
	int n;
	float *num{nullptr};
	string ch;
	cout << "Length of the first number set: ";
	cin >> n;
	num = new float[n];
	calculator c1(n);

	for (int i{0}; i < n; i++)
	{
		cin >> num[i];
		c1.setNumber(num[i], i);
	}

	cout << "First set entered: ";
	for (int i{0}; i < n; i++)
	{
		cout << num[i] << " ";
	}

	delete[] num;

	cout << endl
		 << "Length of the second number set: ";
	cin >> n;
	num = new float[n];
	calculator c2(n);

	for (int i{0}; i < n; i++)
	{
		cin >> num[i];
		c2.setNumber(num[i], i);
	}

	cout << "Second set entered: ";
	for (int i{0}; i < n; i++)
	{
		cout << num[i] << " ";
	}

	delete[] num;

	while (1)
	{
		cout << endl << "Choose operation: ";
		cin >> ch;
		calculator c3;

		if (ch == "+")
			c3 = c1 + c2;

		else if (ch == "-")
			c3 = c1 - c2;

		else if (ch == "*")
			c3 = c1 * c2;

		else if (ch == "/")
			c3 = c1 / c2;

		else if (ch == "exit")
			break;

		else
		{
			cout << "Wrong input" << endl
				 << endl;
			continue;
		}

		cout << c3 << endl;
	}

	return 0;
}