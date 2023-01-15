#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define n 5

typedef struct CarData
{
	string model;
	int totalDist;
	int lastkm;
} cr;

int main(void)
{
	cr car[n];
	string mtnc;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter car model: ";
		cin >> car[i].model;
		cout << "Enter total distance: ";
		cin >> car[i].totalDist;
		cout << "Enter last km: ";
		cin >> car[i].lastkm;
	}

	cout << endl << "Car" << setw(30) << "Total km" << setw(30) << "Last km" << setw(50) << "Needs Maintainance" << endl << endl;

	for (int i = 0; i < n; i++)
	{
		if (car[i].totalDist - car[i].lastkm > 10000)
			mtnc = "YES";

		else
			mtnc = "NO";

		cout << setw(25) << left << car[i].model <<  setw(31) << left << car[i].totalDist << setw(45) << left << car[i].lastkm <<  mtnc << endl;;
	}

	return 0;
}