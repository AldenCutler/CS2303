/***************************  
 * Student.cpp  
 ***************************/ 
#include <string> 
#include <iostream>
#include "student.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
//Constructors
// constructor with 3 arguements
Student::Student(const string &fn, const string &ln, float g){
    firstName = fn;
    lastName = ln;
    GPA = g;
}
// constructor with 2 arguements
Student::Student(const string &fn, const string &ln){
    cout << "This constructor needs to be written" << endl;
}
Student::Student(){
    cout << "This constructor needs to be written" << endl;
}
// Deconstructor
Student:: ~Student(){
    std::cout << "deconstructor called" << std::endl;
}
void Student::set_gpa(float newGPA){
    cout << "This function needs to be written" << endl;
}
float Student::get_gpa(){
    cout << "This function needs to be written" << endl;
}
string Student::get_name(){
    cout << "This function needs to be written" << endl;
} 
// ostream &operator<<(ostream &output, const Student &s1){
//     return output;
// }