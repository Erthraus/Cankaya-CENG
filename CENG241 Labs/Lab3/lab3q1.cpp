#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct course{
    string code;
    double grade;
};

int main(void)
{
    vector<course> crs;
    course temp;
    char answ;
    double cgpa = 0;
    int n = 0;

    do{
        cout << "Enter course code and grade: ";
        cin >> temp.code;
        cin >> temp.grade;
        crs.push_back(temp);
        n++;
        
        while(1)
        {
            cout << "Add new course? (y/n) ";
            cin >> answ;
            if(answ == 'n' || answ == 'y')
                break;
            else
                cout << "You have entere a wrong answer!" << endl;
        }
    } while(answ == 'y');

    cout << "\nList of entered " << n << " courses:";
    
    for(size_t i {0}; i < n; i++)
    {
        cout << "\n- " << crs.at(i).code << ", Grade: " << crs.at(i).grade;
        cgpa += crs.at(i).grade;
    }

    cout << "\nCGPA: " << cgpa/n;

    return 0;
}