#include <iostream>
#include <string>

using namespace std;

class CoffeeMachine 
{
    protected:
        int coffeeAmount;

    public:
        CoffeeMachine() : coffeeAmount{0} {
            //cout << "Coffee constructor has been called" << endl;
        }

        void addCoffee(int x);
};

class LatteMachine: public CoffeeMachine
{
    private:
        int milkAmount;

    public:
        LatteMachine() : milkAmount{0} {
            //cout << "Latte constructor has been called" << endl;
        }

        void addMilk(int x);
        int makeLatte(int n);
};

class FilterCoffeeMachine: public CoffeeMachine
{
    public:
        int makeFilterCoffee(int n);
};

void CoffeeMachine::addCoffee(int x)
{
    coffeeAmount += x;
}

void LatteMachine::addMilk(int x)
{
    milkAmount += x;
}

int LatteMachine::makeLatte(int n)
{
    if(n > coffeeAmount)
        return -1;

    else if(n > milkAmount)
        return -2;

    else
    {
        coffeeAmount -= n;
        milkAmount -= n;
        return 0;
    }
}

int FilterCoffeeMachine::makeFilterCoffee(int n)
{
    if(n > coffeeAmount)
        return -1;

    else{
        coffeeAmount -= n;
        return 0;
    }
}

int main()
{
    LatteMachine latte;
    FilterCoffeeMachine filtcoff;
    string c;
    int x, y, z;

    while(1)
    {
        cout << "Filter or latte? ";
        cin >> c;

        if(c == "none")
        {
            cout << "Goodbye!";
            break;
        }

        else if(c == "filter")
        {
            cout << "How many cups of coffee do you want? ";
            cin >> x;
            
            while((z = filtcoff.makeFilterCoffee(x)) != 0)
            {
                if(z == -1)
                {
                    cout << "Not enough coffee! Add: ";
                    cin >> y;
                    filtcoff.addCoffee(y);
                }
            }

            cout << "Enjoy" << endl << endl;
        }

        else if(c == "latte")
        {
            cout << "How many cups of coffee do you want? ";
            cin >> x; 
            
            while((z = latte.makeLatte(x)) != 0)
            {
                if(z == -1)
                {
                    cout << "Not enough coffee! Add: ";
                    cin >> y;
                    latte.addCoffee(y);
                }

                else if(z == -2)
                {
                    cout << "Not enough milk! Add: ";
                    cin >> y;
                    latte.addMilk(y);
                }
            }

            cout << "Enjoy" << endl << endl;
        }

        else
        {
            cout << "Wrong input" << endl << endl;
        }

    }

    return 0;
}