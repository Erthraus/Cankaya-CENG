#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string& exp)
{
	
	stack<int> st;

	for (int i = 0; i < exp.size(); i++) 
    {		
        if(isspace(exp[i])) continue;

		else if(isdigit(exp[i]))
			st.push(exp[i] - '0');

		else 
        {
			int val1 = st.top();
			st.pop();

			int val2 = st.top();
			st.pop();

			switch(exp[i]) 
            {
                case '+':
                    st.push(val2 + val1);
                    break;
                
                case '-':
                    st.push(val2 - val1);
                    break;
                
                case '*':
                    st.push(val2 * val1);
                    break;
                
                case '/':
                    st.push(val2 / val1);
                    break;
                default:
                    break;
			}
		}
	}
	
    return st.top();
}

int main()
{
	string exp;
    cout << "Enter a postfix expression: ";
    getline(cin, exp);
    //cout << exp << endl;

	cout << "postfix evaluation: " << evaluatePostfix(exp);
	return 0;
}