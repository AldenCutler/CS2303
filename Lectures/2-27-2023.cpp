// February 27, 2023
// Alden Cutler

#include <iostream>

// ------------------------------------------------------------

// Destructors
// - Called when an object is destroyed
// - Called automatically when an object goes out of scope
// - No return type (not even void)
// - No parameters (not even void)
// - Can be overloaded

typedef struct Matrix{
    int length;
    float *data;
    Matrix(int l1); // Constructor
    ~Matrix(); // Destructor
    Matrix operator+(Matrix &B);
    Matrix operator+(Matrix B);
} Matrix;

Matrix::Matrix(int l1){ // Constructor
    length = l1; // Initialize length
    data = new float[length]; // new operator allocates memory
}

Matrix::~Matrix(){ // Destructor
    delete [] data; // Deallocate memory
}


int main(){
    Matrix A(10); // Create a matrix A

    for (int i = 1; i < 2; i++){
        Matrix B(i); // Create a matrix B
        // B is destroyed here
    }

    return 0;
}

// Passing by reference

Matrix Matrix::operator+(Matrix &B){ // pass by reference
    Matrix C(length); 
    for (int i = 0; i < length; i++){
        C.data[i] = data[i] + B.data[i];
    }
    return C;
    // B is not destroyed here
}

// VS

Matrix Matrix::operator+(Matrix B){ // pass by value
    Matrix C(length); 
    for (int i = 0; i < length; i++){
        C.data[i] = data[i] + B.data[i];
    }
    return C;
    // B is destroyed here
}

// when you pass by reference, you are passing the address of the object
// when you pass by value, you are passing a copy of the object
// passing by reference is more efficient because you don't have to copy the object, but it can be more dangerous because you can change the object
// when working with objects, most of the time we want to pass by reference so we don't accidentally delete them when we leave the function

// ------------------------------------------------------------

// Inheritance:
// - Allows you to create a new class from an existing class
// - The new class is called a derived class
// - The existing class is called a base class
// - The derived class inherits all the members of the base class
// - The derived class can add new members
// - The derived class can override members of the base class

// Base class
// - Constructors: 
//      - Base class constructors are called automatically
//      - Base class constructors are called in the order they are declared
//      - Base class constructors are called before derived class constructors
// - Destructors:
//      - Base class destructors are called automatically
//      - Base class destructors are called in the order they are declared
//      - Base class destructors are called after derived class destructors

// Constructors:
// Animal::Animal(string c1){
//     color = c1;    
// }
// Dog::Dog(string tp, string c1):Animal(c1){ --> uses the constructor of the base class to initialize the color
//     type = tp;
// }


// Example:

// Animal.h
// base class
class Animal{
    public:
        void eat();
        void sleep();
};

// Dog.h
// Derived class
// #include "Animal.h"
class Dog: public Animal{
    public:
        void bark();
};

// Animal.cpp
// #include "Animal.h"
#include <iostream>
void Animal::eat(){
    std::cout << "Animal is eating" << std::endl;
}
void Animal::sleep(){
    std::cout << "Animal is sleeping" << std::endl;
}

// Dog.cpp
// #include "Dog.h"
#include <iostream>
void Dog::bark(){
    std::cout << "Dog is barking" << std::endl;
}

// main.cpp
#include <iostream>
// #include "Animal.h"
// #include "Dog.h"
int main(){
    Dog d1; // creating an object of the derived class

    // calling members of the base class
    d1.eat();
    d1.sleep();

    // calling members of the derived class
    d1.bark();

    return 0;
}

// Overloading base class functions:
// - You can override base class functions in the derived class
// - You can use the same name and parameters as the base class function
// - You can use the same name and different parameters as the base class function

// Example:
/*
void Dog::eat(){
    std::cout << "Dog is eating" << std::endl;
}
*/

// protected:
// - Members of the base class that are protected can be accessed by the derived class, but not by the outside world

// Example:
using std::string;
class Animal{
    private:
        string color; // private member, can only be accessed by the class and its functions
    protected:
        string type; // protected member, can be accessed by the class, its functions, and its derived classes
    public:
        void eat();
        void sleep();
        void setColor();
        string getColor();
};



// ------------------------------------------------------------