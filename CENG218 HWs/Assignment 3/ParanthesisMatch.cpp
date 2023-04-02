#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    int left;
    vector<int> left_indices;

    cout << "Enter a string:" << endl;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            left_indices.push_back(i);
        } 
        
        else if (str[i] == ')') {
            if (!left_indices.empty()) {
                left = left_indices.back();
                left_indices.pop_back();
                cout << "(" << left << "," << i << ") ";
            } 
            
            else {
                cout << "\n\")\" at position " << i << " is pairless!" << endl;
            }
        }
    }

    while (!left_indices.empty()) {
        left = left_indices.back();
        left_indices.pop_back();
        cout << "\n\"(\" at position " << left << " is pairless" << endl;
    }

    return 0;
}