#include <iostream>
#include <iomanip>
#include <string>

#define N 3

using namespace std;

class Employee
{
	public:
		void calculateBonus(void);
		void print(void);
		void setName(string x);
		void setSalary(double x);
		void setYears(int x);
			
	private:
		string name;
		int emp_years;
		double salary, bonus;
		
};

void Employee::setName(string x)
{
    name = x;
}

void Employee::setSalary(double x)
{
    salary = x;
}

void Employee::setYears(int x)
{
    emp_years = x;
}

void Employee::calculateBonus(void)
{
    if(emp_years > 20)
        bonus = 0.20;

    else if(emp_years > 15)
        bonus = 0.15;

    else if(emp_years > 10)
        bonus = 0.10;

    else if(emp_years > 5)
        bonus = 0.05;

    else
        bonus = 0;
}

void Employee::print(void)
{
    cout << left << setw(20) << name << setw(20) << emp_years << setw(20) << salary << salary*bonus << endl;
}

int main(void)
{
    Employee emp[N];
    string tempname;
    double tempsalary;
    int tempyears;

    for(size_t i {0}; i < N; i++)
    {
        cout << "Enter employee name, employed years and salary: ";
        cin >> tempname;
        cin >> tempyears;
        cin >> tempsalary;

        emp[i].setName(tempname);
        emp[i].setYears(tempyears);
        emp[i].setSalary(tempsalary);
    }

    cout << endl << left << setw(20) << "Name" << setw(20) << "Years" << setw(20) << "Salary" << "Bonus" << endl;

   for(size_t i {0}; i < N; i++)
    {
        emp[i].calculateBonus();
        emp[i].print();
    }

	return 0;
}