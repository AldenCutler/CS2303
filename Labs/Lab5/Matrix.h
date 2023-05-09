#include <stdio.h>
#include <fstream>
#include <iomanip>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class Matrix{
    public:
        Matrix(int);
        Matrix();
        ~Matrix();
        int getLength();
        float* getData();
        void readMatrix(string fileName);
        Matrix operator+(const Matrix& other) const; //overload + operator needed for the new function        
        void print();
    private:
        float *data;
        int length;
};