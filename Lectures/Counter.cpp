//Counter.cpp
#include <iostream>
#include "Counter.h"

Counter::Counter(){ 
    this_count = 0;
}

Counter::Counter(int x):this_count{x}{ // This is the same as the above function

}

void Counter::setCount(int x){ 
    this_count = x;
}

int Counter::getCount(){ 
    return this_count; // returns the value of this_count
}

Counter Counter::operator+(int a){ 
    Counter newC; // creates a new Counter object
    newC.this_count = this_count + a; // sets the new object's count to the sum of the two counts
    return newC; // returns the new object
}

Counter Counter::operator+(Counter A){
    Counter newC;
    newC.setCount(this_count + A.getCount());
    return newC;
}

Counter operator+(int a, Counter B){
    Counter newC;
    newC.setCount(a + B.getCount());
    return newC;
}

Counter operator-(int a, Counter B){
    Counter newC;
    newC.setCount(a - B.getCount());
    return newC;
}

Counter Counter::operator-(int a){
    Counter newC;
    newC.this_count = this_count - a;
    return newC;
}

Counter Counter::operator-(Counter A){
    Counter newC;
    newC.setCount(this_count - A.getCount());
    return newC;
}