#include <stdbool.h>
#include <math.h>
#include <stdio.h>

// Pseudocode:
// Initialize variables
// Prompt user for value
// Get value from terminal and store in variable
// Loop over all numbers  (x) less than the specified value (v)
    // if the v/x is a whole number (hint, use the % operator which returns the remainder of a/b)
        // then the value is not prime
        // print "This value is not a prime number" to the terminal
        // Exit the loop
// If v/x was never a whole number
    // print "This value is a prime number" to the terminal

int main(void){

    // initialize variables
    int num, is_prime = 0;

    // Prompt user for value
    printf("Please enter a value: \n");
    scanf("%d", &num);


    // 0 and 1 are non-prime numbers
    if (num == 1 || num == 0)
    {
        is_prime = 1;
    }
    
    // loop through every other number that is less than the specified value
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            is_prime = 1;
            break;
        }
        
    }
    

    if (is_prime == 0)
    {
        printf("This value is a prime number");
    } else printf("This value is not a prime number.");
    
}


