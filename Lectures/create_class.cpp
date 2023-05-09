#include <iostream>
#include <string>
#include "Student.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using std::ifstream;


int main(void){
    // create an array of students
    Student myclass[7];

    // open file
    // std::ifstream f1;
    // f1.open("students.txt");

    // load each student into the array
    string fn;
    string ln;
    float gpa;

    // loop through all students
    for (int i = 0; i < 7; i++){
        cin >> fn >> ln >> gpa;
        Student A = {fn, ln, gpa};
        myclass[i] = A;
    }

    // close file
    // f1.close();

    // print list
    for (int i = 0; i < 7; i++){
        cout << myclass[i].get_name() << " " << myclass[i].get_gpa() << endl;
    }   

}