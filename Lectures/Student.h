/***************************  
 * Student.h  
 ***************************/ 
#include <string> 
#include <iostream>
using std::string;
using std::ostream;
class Student { 
  public: 
    void set_gpa(float); 
    float get_gpa();
    string get_name(); 
    //friend ostream &operator<<(ostream &output, const Student &s1);
    Student(const string &fn, const string &ln, float g);
    Student(const string &fn, const string &ln);
    Student(); 
    ~Student(); 
  private: 
    string firstName;
    string lastName; 
    float GPA; 
  
};  // class Student 