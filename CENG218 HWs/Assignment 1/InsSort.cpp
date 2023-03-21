#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::nanoseconds;

void insSort(vector<int>& A)
{
	for(int i=1; i< A.size(); i++) 
	{
		int tmp = A[i];
		int j;
		
    	for(j = i - 1; j>=0 && tmp<A[j]; j--) 
        	A[j+1]= A[j];
      
		A[j+1] = tmp;
   }
}

template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for(int i=0; i<v.size(); i++)
     os << v[i] << " ";
  return os;
}

int main()
{
	
	vector<vector<int>> v(5);

    int n = 500;
    for(int i = 0; i < 5; i++) 
	{
        v[i].resize(n);
        
		for(int j = 0; j < n; j++) 
		{
            v[i][j] = n - j;
        }
        
        n += 500;
    }
	
	for(int i{0}; i < 5; i++)
	{
		vector<int> A = v[i];
		auto t1= high_resolution_clock::now();
		insSort(A);
		auto t2= high_resolution_clock::now();
          
		auto nanoint1 = duration_cast<nanoseconds>(t2-t1);
		//cout << "v" << i+1 << ": " << A << " " << nanoint1.count() << "ns" << endl;
		cout << "v" << i+1 << ": " << " " << nanoint1.count() << "ns" << endl;	
	}
	
	return 0;	
}