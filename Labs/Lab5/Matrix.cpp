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


// write a new function in the Matrix class that overloads the + operator. This operator should return a new matrix object.

Matrix Matrix::operator+(const Matrix& A) const{
    if (length != A.length){
        throw std::invalid_argument("This math cannot be performed.");
    }
    Matrix result(length);
    for (int i = 0; i < length; i++){
        result.data[i] = data[i] + A.data[i];
    }
    return result;
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

/*******************************************************************************
* int getLength(){
*
* Output:
*   Returns length
********************************************************************************/
 int Matrix::getLength(){
    return length;
 }

/*******************************************************************************
* int getData(){
*
* Output:
*   Returns a pointer to the data array
********************************************************************************/
float* Matrix::getData(){
    return data;
}
