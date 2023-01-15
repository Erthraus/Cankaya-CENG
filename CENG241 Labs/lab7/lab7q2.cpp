#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

#define N1 5            //number of villagers
#define N2 5            //number of archers

class Villager
{
    protected:
        int health;
        int attackPower;

    public:
        Villager() : health{20}, attackPower{0} {
            //cout << "Villager constructor has been called" << endl;
        }

        int attack(Villager& target);
        int getHealth();
        void setHealth(int n);
};

class Archer: public Villager
{
    private:
        int nrOfArrows;

    public:
        Archer() : nrOfArrows{5} {
            //cout << "Archer constructor has been called" << endl;
            attackPower = 40;
            health = 60;
        }

        int attack(Villager& target);
        int attack(Archer& target);
        int getNrOfArrows();
};

int Villager::attack(Villager& target)
{
    return 0;
}

int Villager::getHealth()
{
    return health;
}

void Villager::setHealth(int n)
{
    health = n;
}

int Archer::attack(Villager& target)
{
    if(target.getHealth() <= 0)
        return -1;

    else if(nrOfArrows == 0)
        return -2;

    else
    {
        int damage = rand() % (attackPower + 1);
        target.setHealth(target.getHealth() - damage);
        nrOfArrows--;
        return damage;
    }
}

int Archer::attack(Archer& target)
{
    if(target.getHealth() <= 0)
        return -1;

    else if(nrOfArrows == 0)
        return -2;

    else
    {
        int damage = rand() % (attackPower + 1);
        target.setHealth(target.getHealth() - damage);
        nrOfArrows--;
        return damage;
    }
}

int Archer::getNrOfArrows()
{
    return nrOfArrows;
}

int main()
{
    srand(time(0));
    Villager villagers[N1];
    Archer archers[N2];
    int n = 1, offnum, targetnum, temp;
    string offender, target;
    
    while(1)
    {
        cout << "Enter command #" << n++ << ": ";
        cin >> offender;
        cin >> offnum;
        cin >> target;
        cin >> target;
        cin >> targetnum;

        if((offender == target) && (offnum == targetnum))
            break;


        if(offender == "Villager")
        {
            if(offnum >= N1)
                cout << "There is no Villager " << offnum << endl << endl;

            else if(!(villagers[offnum].attack(villagers[0])))
                cout << "Villager" << offnum << " can't attack!" << endl << endl;
        }
            

        else if(offender == "Archer")
        {
            if(offnum >= N2)
                cout << "There is no Archer " << offnum << endl << endl;

            else if(target == "Villager")
            {
                if(targetnum >= N1)
                    cout << "There is no Villager " << targetnum << endl << endl;

                else
                {
                    if((temp = archers[offnum].attack(villagers[targetnum])) == -1)
                        cout << "Villager " << targetnum << " has already been dead." << endl << endl;

                    else if(temp == -2)
                        cout << "Archer " << offnum << " is out of arrows!" << endl << endl;

                    else
                    {
                        cout << "Archer" << offnum << " made " << temp << " damage to Villager" << targetnum << "." << endl << endl;

                        if(villagers[targetnum].getHealth() <= 0)
                            cout << "Villager" << targetnum << " died!" << endl << endl;
                    }
                }
            }

            else
            {
                if(targetnum >= N2)
                    cout << "There is no Archer " << targetnum << endl << endl;

                else
                {
                    if((temp = archers[offnum].attack(archers[targetnum])) == -1)
                        cout << "Archer " << targetnum << " has already been dead." << endl << endl;

                    else if(temp == -2)
                        cout << "Archer " << offnum << " is out of arrows!" << endl << endl;

                    else
                    {
                        cout << "Archer" << offnum << " made " << temp << " damage to Archer" << targetnum << "." << endl << endl;

                        if(archers[targetnum].getHealth() <= 0)
                            cout << "Archer" << targetnum << " died!" << endl << endl;
                    }
                }
            }
        }

        else
            cout << "Wrong input!" << endl << endl;
    }

    return 0;
}