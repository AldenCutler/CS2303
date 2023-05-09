// February 2nd, 2023
// Alden Cutler

#include <stdio.h>

// Stack and Heap
// malloc(), calloc(), free()

// ------------------------------------------------------------

// Well Defined Lifetimes:
// global variables -> entire life of program
// block variables -> entire life of block

// In C:
// Programmer-controlled Lifetimes:
// - create memory in one function and destroy it in another
// - allocate memory in a block and have it exist until the end of the program
// ---> Can do this with the heap.

// Stack:
int global_x;
void fun1(){
    int x;
}
// x is part of the stack frame for fun1

// ------------------------------------------------------------

// Heap:
// Can access at any time from any function.
// - allocated at run time
// - deallocated at run time
// - programmer must keep track of memory
// - accessed only by address

// There are no names in the heap, there must be a pointer to access it from the stack.
// In order to use the heap and the functions that access it, you must include stdlib.h
#include <stdlib.h>

// sizeof() returns the size of a variable in bytes
// ex: sizeof(int) returns 4
// do not use with arrays

// ------------------------------------------------------------

// Allocating Memory:
// malloc() and calloc() are functions that allocate memory on the heap

void* malloc(size_t size);
// void* is a pointer to anything:
// - can be cast to any pointer type (int*, char*, etc.)
// size_t is an unsigned integer type
// - in this function, it's the number of bytes to allocate
// ex: int* a = malloc(sizeof(int)); -> allocates memory on the heap for an int
// ex: float* b = malloc(sizeof(float) * 3); -> allocates memory on the heap for 3 floats
// Warning: compiler will sometimes let you do things you shouldn't do: float* c = malloc(sizeof(int));

// calloc() is similar to malloc(), but it initializes the memory to 0
void* calloc(size_t num, size_t size);
// num is the number of elements to allocate
// size is the size of each element (in bytes, generally using sizeof())
// ex: int* a = calloc(3, sizeof(int)); -> allocates memory on the heap for 3 ints and initializes them to 0

// ------------------------------------------------------------

// Freeing Memory:
// free() is a function that deallocates memory on the heap

void free(void* ptr);
// ptr is a pointer to the memory to deallocate
// ex: free(a); -> deallocates the memory pointed to by a

// ex: allocate an array to store 10 ints:
// int* x = malloc(sizeof(int) * 10);
// or
// int* x = calloc(10, sizeof(int));
// when done with x, free it:
// free(x);

// ------------------------------------------------------------

// Failed Allocations
// happens when you use too much memory
// - accidentally allocate too much memory
// - small devices with limited memory

// Use after free():
// ex:
// free(x);
// x[1] = 2;

// To fix: 
// x = NULL;

// ------------------------------------------------------------

// Using the heap for functions:

int* make_array(int);
void set_array(int*, int); // function prototypes

int main(void){
    int a = 5;
    int* pt1;
    pt1 = make_array(a); // allocates memory for 5 ints
    set_array(pt1, a);

    for (int i = 0; i < a; i++){
        printf("%d\n", pt1[i]);
    }
}

int* make_array(int size){
    int* a1 = calloc(size, sizeof(int)); // allocates memory for size ints
    return a1; // returns the pointer to the array 
}

void set_array(int* a2, int size){
    for (int i = 0; i < size; i++){ // loops through the array and sets each element to i
        a2[i] = i;
    }
}