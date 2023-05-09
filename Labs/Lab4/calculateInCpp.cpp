#include <iostream>

float get_average(float, float, float);

int main(void){
    float x, y, z;
    std::cout <<"Please enter 3 numbers\n";
    std::cin >> x >> y >> z;
    float average = get_average(x, y, z);
    std::cout <<"The average is " << average << std::endl;
    int a = 3%2;
    std::cout << a << std::endl;
    return 0;
}


float get_average(float a, float b, float c){
    float total = a + b + c;
    return total/3.0;
}

// Item                                     Same or different?      C++ implementation
// library for accessing the terminal       different               #include <iostream>
// declaring variables                      same                    float x;
// printing to the terminal                 different               std::cout << "Hello World" << std::endl;
// reading from the terminal                different               std::cin >> x;
// function prototypes                      same                    float get_average(float, float, float);
// function definitions                     same                    float get_average(float a, float b, float c){