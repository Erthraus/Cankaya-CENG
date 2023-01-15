#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Course {
	private:
		int mtG, hwG, finG;
		double mtW, hwW, finW;
		string name;
		string letterGrade;
		
	public:
		Course() : mtW{0.3}, hwW{0.2}, finW{0.5} {
			
		}
		
		Course(double mtW, double hwW, double finW) : mtW{mtW}, hwW{hwW}, finW{finW} {
			
		}
		
		void calculate();
		
		void set_midterm(int grade);
		int get_midterm();
		
		void set_homework(int grade);
		int get_homework();
		
		void set_final(int grade);
		int get_final();
		
		void set_name(string name);
		string get_name();
		
		string get_letterGrade();
};

void Course::calculate()
{
	int avg = mtG * mtW + hwG * hwW + finG * finW;
	
	if(avg >= 90)
		letterGrade = "AA";
		
	else if(avg >= 85)
		letterGrade = "BA";
		
	else if(avg >= 80)
		letterGrade = "BB";
		
	else if(avg >= 70)
		letterGrade = "CB";
		
	else if(avg >= 60)
		letterGrade = "CC";
		
	else if(avg >= 50)
		letterGrade = "DC";
		
	else if(avg >= 45)
		letterGrade = "DD";
		
	else if(avg >= 35)
		letterGrade = "FD";
		
	else
		letterGrade = "FF";
}

void Course::set_midterm(int grade)
{
	this->mtG = grade;
}

int Course::get_midterm()
{
	return mtG;
}

void Course::set_homework(int grade)
{
	this->hwG = grade;
}

int Course::get_homework()
{
	return hwG;
}

void Course::set_final(int grade)
{
	this->finG = grade;
}

int Course::get_final()
{
	return finG;
}

void Course::set_name(string name)
{
	this->name = name;
}

string Course::get_name()
{
	return name;
}

string Course::get_letterGrade()
{
	return letterGrade;
}

int main()
{
	string tempname;
	int temp;
	double w1, w2, w3;
	
	cout << "Enter weights for second course: ";
	cin >> w1;
	cin >> w2;
	cin >> w3;
	
	Course c1, c2{w1, w2, w3};
	
	cout << "Enter first course name: ";
	cin >> tempname;
	c1.set_name(tempname);
	cout << "Enter first course grades: ";
	cin >> temp;
	c1.set_midterm(temp);
	cin >> temp;
	c1.set_homework(temp);
	cin >> temp;
	c1.set_final(temp);
	c1.calculate();
	
	cout << "Enter second course name: ";
	cin >> tempname;
	c2.set_name(tempname);
	cout << "Enter second course grades: ";
	cin >> temp;
	c2.set_midterm(temp);
	cin >> temp;
	c2.set_homework(temp);
	cin >> temp;
	c2.set_final(temp);
	c2.calculate();
	
	cout << endl <<left << setw(10) << "Course" << setw(10) << "Midterm" << setw(10) << "Homework" << setw(10) << "Final" << "Letter" << endl;
	cout << left << setw(10) << c1.get_name() << setw(10) << c1.get_midterm() << setw(10) << c1.get_homework() << setw(10) << c1.get_final() << c1.get_letterGrade() << endl;
	cout << left << setw(10) << c2.get_name() << setw(10) << c2.get_midterm() << setw(10) << c2.get_homework() << setw(10) << c2.get_final() << c2.get_letterGrade() << endl;
	
	return 0;
}