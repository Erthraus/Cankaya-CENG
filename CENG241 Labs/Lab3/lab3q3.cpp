#include <iostream>
#include <string>

using namespace std;

typedef struct numberlist{
    int list[10];
    string direction;
} num;

void func1(num *p1)
{
	if((*p1).direction == "left-to-right")
	{
		for(size_t i {0}; i < 9; i++)
			(*p1).list[i+1] += (*p1).list[i];
	}
	
	else if((*p1).direction == "right-to-left")
	{
		for(size_t i {9}; i > 0; i--)
			(*p1).list[i-1] += (*p1).list[i];
	}
	
	else
		cout << "You have entered a wrong direcction!" << endl;
}

void func2(num &p2)
{
	if(p2.direction == "left-to-right")
	{
		for(size_t i {0}; i < 9; i++)
			p2.list[i+1] += p2.list[i];
	}
	
	else if(p2.direction == "right-to-left")
	{
		for(size_t i {9}; i > 0; i--)
			p2.list[i-1] += p2.list[i];
	}
	
	else
		cout << "You have entered a wrong direcction!" << endl;
}

int main(void)
{
    num list[2];
    size_t flag = 1;
	
	for(size_t i {0}; i < 2; i++)
	{
		cout << "Enter 10 integers and order of summation: ";
   	 	for(size_t j {0}; j < 10; j++)
        	cin >> list[i].list[j];
		cin >> list[i].direction;
		
		if(flag == 1)
    		func1(list);
    	else
    		func2(list[1]);
    	
		cout << "Reult: ";
    	
    	for(size_t j {0}; j < 10; j++)
			cout << list[i].list[j] << " ";
			
		cout << endl;
		flag++;
	}
    


    return 0;
}