//count_values.cpp
#include <iostream>
#include "Counter.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(void){
    Counter num7;
    Counter num5;
    for (int i = 2 ; i < 100; i++){
        if (i % 7 == 0){
            num7 = 1 + num7;
            cout << num7.getCount() << endl;
        }
    }
    for (int i = 2 ; i < 100; i++){
        if (i % 5 == 0){
            num5 = num5 + 1;
             cout << num5.getCount() << endl;
        }
    }
    Counter num5_7 = num7 + num5;

    cout << "Numbers divisible by 5 and numbers divisible by 7: ";
    cout << num5_7.getCount() << endl;

    // Remove items that are devisible by 5 and by 7
    for (int i = 2 ; i < 100; i++){
        if (i % 7 == 0 & i % 5 == 0){
            num7 = num7 - 1;
        }
    }
    cout << "Numbers divisible by 7 and not 5: " << num7.getCount() << endl;
    num5_7 = num7 + num5;
    cout << "Number of unique values divisible by 5 or 7: " << num5_7.getCount() << endl;
    // Test other subtraction functions
    num5_7 = num7 - num5;
    cout << "num7 - num5:" << num5_7.getCount() << endl;
    num5_7 = 10 - num7;
    cout << "10 - num7: " << num5_7.getCount() << endl;
    return 0;
}
