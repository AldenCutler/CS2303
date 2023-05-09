#include <iostream>

int checkPrime(int);

int main(void){
    int value;

    std::cout << "Please enter a value:\n";

    std::cin >> value;

    int isPrime = checkPrime(value);
    if (isPrime == 1){
        std::cout << "This value is a prime number\n";
    } else std::cout << "This value is not a prime number\n";
}

int checkPrime(int value){
    int x = 2;
    int notPrime = 0;
    
    while (x < value && notPrime == 0){
        if (value % x == 0){
            notPrime = 1;
            return 0;
        }
        x++;
    }
    
    if (notPrime == 0){
        return 1;
    }
}