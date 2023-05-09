// February 21, 2023
// Alden Cutler

// review of overloading
// two or more functions with the same name but different parameters
// same with constructors
// add(int a, int b)
// add(float a, float b)

// overloading built-in operators
// 7 + 8 -> calls the built in operator + (int) function
// Object + 8 -> calls the built in operator + (int) function for the Object

// friend functions
// friend functions are not part of the class, but can access the private members of the class

// if a function is a friend function, don't use the double colon (::) operator
// if a function is a member (not a friend) function, use the double colon (::) operator

// count_values.cpp
//count_values.cpp
#include <iostream>
#include "Counter.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(void){
    Counter num3; // initialize a counter object
    for (int i = 31 ; i < 122; i++){ // loop through all the numbers from 31 to 122
        if (i % 3 == 0){ // if the number is divisible by 3
            num3 = num3 + 1; // add 1 to the counter
        }
    }
    cout << num3.getCount() << endl; // print the number of numbers divisible by 3
}


// << overloading
// cout << 7; -> calls the built in operator << (int) function
// cout is of type ostream

// ostream& operator<<(ostream& os, Counter& A){ // overload the << operator for Counter objects
//     os << A.getCount(); // print the count of the Counter object
//     return os; // return the ostream object
// }

// prototype: friend ostream& operator<<(ostream&,  Counter&);
// ampersand (&) means to pass by reference

