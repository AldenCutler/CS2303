#include <iostream>
#include <string>
#include <iomanip>
#include "Matrix.h"
Matrix::Matrix(int l1){
    length = l1;
    data = new float[length];
    
}
Matrix::Matrix(){
    length = 0;
    data = NULL;
    
}
void Matrix::readMatrix(string fileName) {
    ifstream input;
    input.open(fileName);
    
    for (int i = 0; i < length; i++){
        input >> data[i];
    }
    input.close();
}
/*******************************************************************************
* void print(Matrix& A){
*
* Output:
*   Prints A to the screen
********************************************************************************/
void Matrix::print(){
   // print values to screen
    for (int i = 0; i < length; i++){
       cout << std::setw(8) << data[i];  
    }
    printf("\n");
}
/*******************************************************************************
* Matrix::~Matrix()
*
* Deconstructor for Matrix object
********************************************************************************/
Matrix::~Matrix(){
    delete data;
}
int Matrix::getLength(){
    return length;
 }
float* Matrix::getData(){
    return data;
}

Matrix Matrix::operator+(Matrix &B){ // Allows A + B
    Matrix C(length);
    for (int i = 0; i < length; i ++){
        C.data[i] = data[i] + B.data[i];
    }
    return C;
}

// 3 new functions

Matrix Matrix::operator+(float num){ // Allows A + 2.2
    Matrix C(length);
    for (int i = 0; i < length; i ++){
        C.data[i] = data[i] + num;
    }
    return C;
}

Matrix operator+(float num, const Matrix& A){   // Allows 2.2 + A
    Matrix C(A.length);
    for (int i = 0; i < A.length; i ++){
        C.data[i] = A.data[i] + num;
    }
    return C;
}

ostream& operator<<(ostream& os, const Matrix& A){ // Allows cout << A
    for (int i = 0; i < A.length; i++){
       os << std::setw(8) << A.data[i];  
    }
    os << endl;
    return os;
}