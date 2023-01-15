#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cout << "How many numbers letters are you going to enter? ";
    cin >> n;
    char *ch = new char[n];
    int *re = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter letter and how many times it will be repeated: ";
        cin >> ch[i];
        cin >> re[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < re[i]; j++)
            cout << ch[i];
    }

    delete[] ch;
    delete[] re;

    return 0;
}