#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car
{
    protected:
        string brandname;
        int modelyear;
        int price;
        int totalCost;

    public:
        Car()
        {
            //cout << "Car ctr" << endl;
        }

        Car(string name, int year, int price) : brandname{name}, modelyear{year}, price{price}
        {
            //cout << "Car overload ctr" << endl;
        }

        Car(const Car& obj)
        {
            //cout << "Car copyctr" << endl;
            brandname = obj.brandname;
            modelyear = obj.modelyear;
            price = obj.price;
            totalCost = obj.totalCost;
        }

        string getBrandname()
        {
            return brandname;
        }

        void setBrandname(string name)
        {
            brandname = name;
        }

        int getModelyear()
        {
            return modelyear;
        }

        void setModelyear(int year)
        {
            modelyear = year;
        }

        int getPrice()
        {
            return price;
        }

        void setPrice(int price)
        {
            this->price = price;
        }

        int getTotalCost()
        {
            return totalCost;
        }

        void setTotalCost(int cost)
        {
            totalCost = cost;
        }
};

class ElectricCar: public Car
{
    protected:
        int NumberOfBatteries;
        int electricCost;

    public:
        ElectricCar()
        {
            //cout << "EC ctr" << endl;
        }

        ElectricCar(string name, int year, int price, int num, int ecost) : Car(name, year, price), NumberOfBatteries{num}, electricCost{ecost}
        {
            //cout << "EC overload ctr" << endl;
        }

        ElectricCar(const ElectricCar& obj) : Car(obj)
        {
            //cout << "EC copyctr" << endl;
            NumberOfBatteries = obj.NumberOfBatteries;
            electricCost = obj.electricCost;
        }

        friend ostream& operator <<(ostream &os, const ElectricCar &obj);

        int getNumberOfBatteries()
        {
            return NumberOfBatteries;
        }

        void setNumberOfBatteries(int num)
        {
            NumberOfBatteries = num;
        }

        int getElectricCost()
        {
            return electricCost;
        }

        void setElectricCost(int cost)
        {
            electricCost = cost;
        }
};

class  GasolineCar: public Car
{
    protected:
        int engineVolume;
        int fuelCost;

    public:
        GasolineCar()
        {
            //cout << "GC ctr" << endl;
        }

        GasolineCar(string name, int year, int price, int vol, int fcost) : Car(name, year, price), engineVolume{vol}, fuelCost{fcost}
        {
            //cout << "GC overload ctr" << endl;
        }

        GasolineCar(const GasolineCar& obj) : Car(obj)
        {
            //cout << "GC copyctr" << endl;
            engineVolume = obj.engineVolume;
            fuelCost = obj.fuelCost;
        }

        friend ostream& operator <<(ostream &os, const GasolineCar &obj); 

        int getEngineVolume()
        {
            return engineVolume;
        }

        void setEngineVolume(int vol)
        {
            engineVolume = vol;
        }

        int getFuelCost()
        {
            return fuelCost;
        }

        void setFuelCost(int cost)
        {
            fuelCost = cost;
        }
};

class HybridCar: public ElectricCar, public GasolineCar
{
    public: 
        HybridCar()
        {
            //cout << "HC ctr" << endl;
        }

        HybridCar(const HybridCar& obj) : GasolineCar(obj), ElectricCar(obj)
        {
            //cout << "HC copyctr" << endl;
        }

        friend ostream& operator <<(ostream &os, const HybridCar &obj);
};

ostream& operator <<(ostream &os, const ElectricCar &obj)
{
    os << obj.brandname << " " << obj.modelyear << " price: " << obj.price << endl;
    os << "Number of Batteries: " << obj.NumberOfBatteries << " Electric Cost: " << obj.electricCost << " Total Cost: " << obj.totalCost << endl;

    return os;
}

ostream& operator <<(ostream &os, const GasolineCar &obj)
{
    os << obj.brandname << " " << obj.modelyear << " price: " << obj.price << endl;
    os << "Engine Volume: " << obj.engineVolume << " Fuel Cost: " << obj.fuelCost << " Total Cost: " << obj.totalCost << endl;

    return os;
}

ostream& operator <<(ostream &os, const HybridCar &obj)
{
    os << obj.ElectricCar::brandname<< " " << obj.ElectricCar::modelyear << " price: " << obj.ElectricCar::price << endl;
    os << "Number of Batteries: " << obj.NumberOfBatteries << " Electric Cost: " << obj.electricCost << endl;
    os << "Engine Volume: " << obj.engineVolume << " Fuel Cost: " << obj.fuelCost << " Total Cost: " << obj.ElectricCar::totalCost << endl;

    return os;
}

int main()
{
    int ch, year, price, batt_vol, cost;
    string name;
    vector<ElectricCar> elist;
    vector<GasolineCar> glist;
    vector<HybridCar> hlist;

    while(1)
    {
        cout << "1- Electric Car" << endl;
        cout << "2- Gasoline Car" << endl;
        cout << "3- Hybrid Car" << endl;
        cout << "4- Exit" << endl;
        cout << "Choice: ";
        cin >> ch;

        if(ch == 4)
            break;

        if(ch != 1 && ch != 2 && ch != 3)
        {
            cout << "Wrong Input" << endl;
            continue;
        }
        
        cout << "Enter brand name: ";
        cin >> name;
        cout << "Enter model year: ";
        cin >> year;
        cout << "Price: ";
        cin >> price;
        
        if(ch == 1)
        {
            cout << "Number of Batteries: ";
            cin >> batt_vol;
            cout << "Electric Cost: ";
            cin >> cost;
            ElectricCar ec(name, year, price, batt_vol, cost);
            ec.setTotalCost(cost);
            elist.push_back(ec);
        }

        else if(ch == 2)
        {
            cout << "Engine Volume(CC): ";
            cin >> batt_vol;
            cout << "Fuel Cost: ";
            cin >> cost;
            GasolineCar gc(name, year, price, batt_vol, cost);
            gc.setTotalCost(cost);
            glist.push_back(gc);
        }

        else if(ch == 3)
        {
            int cost2, vol;
            cout << "Number of Batteries: ";
            cin >> batt_vol;
            cout << "Electric Cost: ";
            cin >> cost;
            cout << "Engine Volume(CC): ";
            cin >> vol;
            cout << "Fuel Cost: ";
            cin >> cost2;
            HybridCar hc;
            hc.ElectricCar::setBrandname(name);
            hc.setEngineVolume(vol);
            hc.setFuelCost(cost2);
            hc.setNumberOfBatteries(batt_vol);
            hc.setElectricCost(cost);
            hc.ElectricCar::setModelyear(year);
            hc.ElectricCar::setPrice(price);
            hc.ElectricCar::setTotalCost(cost + cost2);
            hlist.push_back(hc);
        }
    }

    if(elist.size() == 0 && glist.size() == 0 && hlist.size() == 0)
        return 0;

    int minlist = 0, minloc = 0, mincost = 0;

    cout << endl << "Electric Cars: " << endl; 
    for(int i{0}; i < elist.size(); i++)
    {
        if(mincost == 0)
            mincost = elist.at(i).getPrice();
        cout << i + 1 << "- " << elist.at(i);
        if(elist.at(i).getTotalCost() < mincost)
        {
            minloc = i;
            mincost = elist.at(i).getTotalCost();
        }
    }

    cout << endl << "Gasoline Cars: " << endl; 
    for(int i{0}; i < glist.size(); i++)
    {
        if(mincost == 0)
        {
            mincost = glist.at(i).getPrice();
            minlist = 1;
        }
        cout << i + 1 << "- " << glist.at(i);
        if(glist.at(i).getTotalCost() < mincost)
        {
            minlist = 1;
            minloc = i;
            mincost = glist.at(i).getTotalCost();
        }
    }

    cout << endl << "Hybrid Cars: " << endl; 
    for(int i{0}; i < hlist.size(); i++)
    {
        if(mincost == 0)
        {
            mincost = hlist.at(i).ElectricCar::getPrice();
            minlist = 2;
        }
        cout << i + 1 << "- " << hlist.at(i);
        if(hlist.at(i).ElectricCar::getTotalCost() < mincost)
        {
            minlist = 2;
            minloc = i;
            mincost = hlist.at(i).ElectricCar::getTotalCost();
        }
    }  

    if(minlist == 0)
        cout << endl << elist.at(minloc).getBrandname() << " has the minimum cost of all cars.";

    else if(minlist == 1)
        cout << endl << glist.at(minloc).getBrandname() << " has the minimum cost of all cars.";

    else
        cout << endl << hlist.at(minloc).ElectricCar::getBrandname() << " has the minimum cost of all cars.";
    
    return 0;
}