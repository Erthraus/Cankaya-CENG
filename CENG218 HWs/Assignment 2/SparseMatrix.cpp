#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

class MatrixTerm {
	public:
    	int row, col;
    	int value;
};

class SparseMatrix {
	private:
    	int rows, cols, Nterms, capacity = 8;

	public:
		MatrixTerm *smArray;
		
		SparseMatrix() {
			smArray = new MatrixTerm[capacity];
		}
		
		SparseMatrix(int nrow, int ncol, int Nt) : SparseMatrix() {
			rows = nrow, cols = ncol, Nterms = Nt;
			
			if(Nterms > capacity)
				resizeArr(); 
		}
		
		/*SparseMatrix(const SparseMatrix& old) : SparseMatrix(old.rows, old.cols, old.Nterms) {
			cout << "Copy C" << endl;
			
			for(size_t i = 0; i < Nterms; i++) {
				smArray[i].row = old.smArray[i].row;
				smArray[i].col = old.smArray[i].col;
				smArray[i].value = old.smArray[i].value;
			}
		}*/
		
		~SparseMatrix() {
			delete[] smArray;
		}
		
    	void generateRandomSparseMatrix(int nrows, int ncols, int ZeroPercentage) {
    		rows = nrows;
    		cols = ncols;
        	int total = nrows * ncols;
        	Nterms = total - (total * ZeroPercentage / 100);
        	
        	if(Nterms > capacity)
        		resizeArr();
        	
        	bool flag;
        	MatrixTerm temp;
        	
        	for(size_t i = 0; i < Nterms; i++) {
        		flag = true;
        		temp.col = rand() % ncols + 1;
        		temp.row = rand() % nrows + 1;
        		temp.value = rand() % 9 + 1;
        		
        		for(size_t j = 0; j < i; j++) {
        			if(smArray[j].col == temp.col && smArray[j].row == temp.row) {
        				flag = false;
        				i--;
        				break;
					}	
				}
				
				if(flag)
					smArray[i] = temp;
			}
			
			Sort();		
    	}
    	
    	//Insertion Sort
    	void Sort() {
    		MatrixTerm temp;
    		
    		for(size_t i = 1; i < Nterms; i++) {
      		 	temp = smArray[i]; 
     			int j = i - 1;
      			
				while(j >= 0 && temp.row <= smArray[j].row) {
					if(temp.row == smArray[j].row && temp.col > smArray[j].col)       	
						break;				 
					smArray[j+1] = smArray[j];
	 				j--;		
      			}
      			
				smArray[j+1] = temp;
   			}
		} 
		
		SparseMatrix transpose() {
			SparseMatrix transpose(cols, rows, Nterms);
			
			for(size_t i = 0; i < Nterms; i++) {
				transpose.smArray[i].row = smArray[i].col;
				transpose.smArray[i].col = smArray[i].row;
				transpose.smArray[i].value = smArray[i].value;
			}
			
			transpose.Sort();
			return transpose;
		}
    	
    	/*void printMatrix() {
			for(size_t i = 0; i < Nterms; i++)
				cout << smArray[i].row << " ";
			cout << endl;

			for(size_t i = 0; i < Nterms; i++)
				cout << smArray[i].col << " ";
			cout << endl;
			
			for(size_t i = 0; i < Nterms; i++)
				cout << smArray[i].row << " ";
			cout << endl;
		}*/
    	
    	void resizeArr() {
    	//	int tempcap = capacity;
    		
    		while(capacity < Nterms)
    			capacity *= 2;
    			
    	/*	MatrixTerm *temp = new MatrixTerm[tempcap];
    		
    		for(size_t i = 0; i < tempcap; i++) {
    			temp[i].row = smArray[i].row;
    			temp[i].col = smArray[i].col;
    			temp[i].value = smArray[i].value;
			}*/
			
			delete[] smArray;
    		smArray = new MatrixTerm[capacity];
    		
    	/*	for(size_t i = 0; i < tempcap; i++) {
    			smArray[i].row = temp[i].row;
    			smArray[i].col = temp[i].col;
    			smArray[i].value = temp[i].value;
			}
			
			delete[] temp;*/
		}
		
		friend ostream& operator<<(ostream& OS, SparseMatrix& SM) {
			OS << "[ ";
			for (size_t i = 0; i < SM.Nterms; i++) {
        		OS << SM.smArray[i].row << " ";
    		}
    		OS << "]" << endl;
    		
    		OS << "[ ";
    		for (size_t i = 0; i < SM.Nterms; i++) {
        		OS << SM.smArray[i].col << " ";
    		}
    		OS << "]" << endl;
    		
    		OS << "[ ";
    		for (size_t i = 0; i < SM.Nterms; i++) {
        		OS << SM.smArray[i].value << " ";
    		}
    		OS << "]" << endl;
        	
    		return OS;
		}	
};

int main() {
	srand(time(0));
	int nrow, ncol, zP;
    SparseMatrix A;
    cout << "Enter number of rows: ";
    cin >> nrow;
    cout << "Enter number of columns: ";
    cin >> ncol;
    cout << "Enter the zero percentage: ";
    cin >> zP;
    
	A.generateRandomSparseMatrix(nrow, ncol, zP);
	SparseMatrix T = A.transpose();
    cout << "Sparse Matrix" << endl << A << endl;
    cout << "Transpose" << endl << T;
    //A.printMatrix();
    
	return 0;
}