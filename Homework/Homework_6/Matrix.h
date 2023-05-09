#include <stdio.h>
#include <fstream>
#include <iostream>
using std::string;
using std::endl;
using std::ifstream;
using std::ostream;
using std::cout;

class Matrix{
    public:
        Matrix(int);
        Matrix();
        ~Matrix();
        void readMatrix(string fileName);
        int getLength();
        float* getData();
        Matrix operator+(Matrix &B);
        
        Matrix operator+(float); // Allows A + 2.2
        friend Matrix operator+(float, const Matrix& A);    // Allows 2.2 + A
        friend ostream& operator<<(ostream& os, const Matrix& A); // Allows cout << A
        
        void print();
    private:
        float *data;
        int length;
};
