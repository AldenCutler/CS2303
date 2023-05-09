// January 19th, 2023
// Alden Cutler

int z = 5;
// variable defined outside of main is called a "global variable"
// int: type
// z: identifier


// Scope: Where is the variable visible?
// Duration: When does the variable exist?
// Linkage: Where can the variable be accessed? (in different files)


int x = 1;
int main(void){
    int y = x + 1;
    return 0;
}
// x: not in function, global variable, file scope (visible in entire file)
// y: in function ({} block), block scope (visible in block)


int main(void){
    int a = 1;
    if (a < 5){
        int b = 2;
    }
}
// a is visible in the entire function, but not the rest of the file
// b is only visible inside the if statement, not anywhere else


// Duration: when a variable is created and destroyed

int x = 1;
int main(void){
    int y = x + 1;
    return 0;
}
// x: static storage duration
// - allocated when program starts
// - deallocated when program ends

// y: automatic storage duration
// - allocated when block starts
// - deallocated when block ends


// Functions:
// most function identifiers have file scope, meaning they're visible anywhere in the file


// Changing scope and duration:
// there are keywords that you can use to change the scope and duration of variables
void myCounter(void){
    static int x = 10; // initialized only once
    x++;
    printf("Static variable value: %d\n", x);
}

int main(void){
    myCounter(); // x == 11
    myCounter(); // x == 12
    myCounter(); // x == 13
}

//-------------------------------------------------------------------------------------------------------

// Using printf to format output:

int main(void){
    printf("text");

    float x = 2.0/3.0;
    float y = 2000;
    printf("%f\n%f]n", x, y); // output isn't lined up correctly:
    // 0.666667
    // 2000.000000
    // to fix that: 
    printf("%8.3f\n%8.3f\n", x, y); // 8.3 means use 8 spots to print and put 3 digits after the decimal point (the . counts as a spot)
    // new output: 
    //    0.667
    // 2000.000
}

// %8.2f: print using 8 spots, with 2 after the decimal point
// %8d: print an integer using 8 spots 
// %8.2e: print using scientific notation with 2 digits in exponent
// %08.2: print using 8 spots, with 2 after decimal point, pad left with 0s
// %s: print a string of characters


// Write a program that prints 5/n where n ranges from 1 to 20, print with decimal points aligned:
#include <stdio.h>
int main(void){
    for (float n = 1; n <= 20; n++)
    {
        float x = 5/n;
        printf("%5.2f\n", x);   
    }   
}
// Output: 
/*
 5.00
 2.50
 1.67
 1.25
 1.00
 0.83
 0.71
 0.62
 0.56
 0.50
 0.45
 0.42
 0.38
 0.36
 0.33
 0.31
 0.29
 0.28
 0.26
 0.25
 */