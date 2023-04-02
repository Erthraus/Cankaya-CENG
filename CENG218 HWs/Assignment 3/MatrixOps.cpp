#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    Matrix() {}

    Matrix(int rows, int cols): rows(rows), cols(cols) {
        data.resize(rows, vector<int>(cols, 0));
    }

    void generateRandom(int nrows, int ncols) {
        rows = nrows;
        cols = ncols;
        data.resize(rows, vector<int>(cols, 0));

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                data[i][j] = rand() % 10;
            }           
        }       
    }

    friend ostream& operator<<(ostream &os, const Matrix& M) {
        for (int i = 0; i < M.rows; i++) {
            for (int j = 0; j < M.cols; j++) {
                os << M.data[i][j] << " ";
            }
            os << endl;
        }

        return os;
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("Matrix dimensions must match.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator-(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("Matrix dimensions must match.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) {
        if (cols != other.rows) {
            throw runtime_error("Matrix dimensions must match.");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    Matrix operator/(const int scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] / scalar;
            }
        }

        return result;
    }

    Matrix operator*(const int scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }

        return result;
    }

    void setData(int i, int j, int val) {
        data[i][j] = val;
    }

    int getData(int i, int j) const {
        return data[i][j];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }
};

int main() {
    srand(time(0));
    bool flag = true;
    int nrows, ncols, scalar;
    char choice;
    Matrix A, B;

    do{
        cout << "Enter the number of rows and columns for the first Matrix: ";
        cin >> nrows;
        cin >> ncols;
        A.generateRandom(nrows, ncols);

        cout << "Enter the number of rows and columns for the second Matrix: ";
        cin >> nrows;
        cin >> ncols;
        B.generateRandom(nrows, ncols);
		
		cout << endl << A << "\n\n" << B << endl;
        cout << "Which operation do you want to perform (+, -, *, /): ";
        cin >> choice;

        switch(choice) {
            case '+':
                try {
                    cout << endl << A + B;
                }
                catch(const runtime_error& error) {
                    cerr << error.what() << endl;
                }           
                
                break;
            
            case '-':
                try {
                    cout << endl << A - B;
                }
                catch(const runtime_error& error) {
                    cerr << error.what() << endl;
                }  

                break;

            case '*':
                cout << "Do you want to multiply with a number or with the second matrix (1 or 2): ";
                cin >> choice;
                
                if(choice == '1') {
                    cout << "Enter a number: ";
                    cin >> scalar;
                    try {
                        cout << endl << A * scalar;
                    }
                    catch(const runtime_error& error) {
                        cerr << error.what() << endl;
                    }  
                }

                else if(choice == '2') {
                    try {
                        cout << endl << A * B;
                    }
                    catch(const runtime_error& error) {
                        cerr << error.what() << endl;
                    }  
                }
                
                else {
                    cout << "Wrong input" << endl;
                }

                break;

            case '/':
                cout << "Enter a number: ";
                cin >> scalar;
                try {
                    cout << endl << A / scalar;
                }
                catch(const runtime_error& error) {
                    cerr << error.what() << endl;
                }  
                break;

            default:
                cout << "Wrong input" << endl;
                break;
        }

        cout << "Do you want to retry (y or n): ";
        cin >> choice;
        
        if(choice == 'y')
            flag = true;
        else
            flag = false;

    }while(flag);

    return 0;
}