#include "Cat.h"

Cat::Cat(string tp, string c):Animal(c){ // call base class constructor
    type = tp;
}

Cat::Cat():Animal("black"){ // default type to "unk"
    type = "unk";
}

void Cat::setType(string tp) { // set type
    type = tp;
}

void Cat::displayInfo(string c) { // print "I am a <type> and my color is <c>"
    cout << "I am a " << type << endl;
    cout << "My color is " << c << endl;
}

void Cat::meow(){ // print "I can speak! Meow meow!!"
    cout << "I can speak! Meow meow!!" << endl;
}