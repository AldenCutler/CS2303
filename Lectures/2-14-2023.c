// 2/14/2023
// Alden Cutler
// ----------------------------------------------

// Structs within structs:

#include <stdio.h>
#include <stdlib.h>

struct point{ // define a struct called point
    int x; // define the x coordinate
    int y; // define the y coordinate
};
struct triangle{ // define a struct called triangle
    struct point A; // define a struct point A;
    struct point B; // define a struct point B;
    struct point C; // define a struct point C;
};
typedef struct point Point; // define a new type called Point
typedef struct triangle Triangle; // define a new type called Triangle

int main(void){
    Triangle firstT;
    // firstT.A.x = 1;
    return 0;
}

// --> Stack:
// main:
    // firstT:
        // A:
            // x:
            // y:
        // B:
            // x:
            // y:
        // C:
            // x:
            // y:

// ----------------------------------------------

// Structs with pointers:

#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
    struct point* clock; // pointer to another point variable in the clock-wise direction
    struct point* counter; // pointer to another point variable in the counter-clock-wise direction
};
struct rect{
    struct point corners[4]; // array of 4 point variables
};

typedef struct point Point;
typedef struct rect Rect;

// example main with structs and pointers:
int main(void){
    FILE *f1 = fopen("coord.txt", "r");
    Rect thisRect;
    float x;
    float y;
    for (int i = 0; i < 4; i++){ // loop over the corners
        fscanf(f1, "%f %f", &x, &y); // read the x and y coordinates
        Point A = {x, y}; // create a point variable
        thisRect.corners[i] = A; // assign the point variable to the array of corners, copy by value
    }

    for (int i = 0; i < 3; i++){ 
        thisRect.corners[i].clock = &(thisRect.corners[i+1]); // assign the clock-wise pointer to the next point in the array
    }
    thisRect.corners[3].clock = &thisRect.corners[0]; // assign the clock-wise pointer of the last point to the first point
}

// ----------------------------------------------

