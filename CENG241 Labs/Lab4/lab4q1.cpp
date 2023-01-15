#include <iostream>
#include <string>

using namespace std;

class Calculator
{
    public:
        int op1, op2;
        double res;
        string op;
        void run(void);
        
};

void Calculator::run(void)
{
    if(op == "divide")
    	res = (double)op1 / (double)op2;

    else if(op == "add")
            res = op1 + op2;

    else if(op == "subtract")
            res = op2- op1;

    else if(op == "multiply")
            res = op1 * op2;

    else
    {
        cout << "Unknown Operation";
        return;
    }
    
    cout << "Result is: " << res;
}

int main(void)
{
    Calculator cal1;
    string ignore;

    cout << "Enter your operation: ";
    cin >> cal1.op;
    cin >> cal1.op1; 
    cin >> ignore;
    cin >> cal1.op2;
    
    cal1.run();

    return 0;
}