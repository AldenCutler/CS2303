#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // float number1 = 7.3;
    // float number2;

    // float * fPtr;
    // fPtr = &number1;

    // printf("The value of number1 is %f\n", *fPtr);

    // fPtr = &number2;

    // printf("The value of number2 is %f\n", *fPtr);

    // printf("The address of number1 is %p\n", &number1);
    // printf("The address stored in fPtr is %p\n", fPtr);
    // the values are not the same

    // 5:
    int num_days = 5;
    int num_values = 4;
    int *dataArray[num_days]; // array including 5 items, each item is a pointer to an int

    for (int j = 0; j < num_days; j++)
    {                                                      // loop through num_days  / loop through the array / loop 5 times
        int *thisArray = malloc(num_values * sizeof(int)); // allocate memory for an array of 4 ints
        thisArray[0] = j;                                  // set the first value of the new array to j
        dataArray[j] = thisArray;                          // set the pointer in the array to point to the new array
    }

    /*
    Essentially what this loop does is it turns the array of pointers into an array of arrays,
    making the original array now two dimensional instead of one dimensional.

    What the array looks like now is:
    The first column contains the pointers to the arrays, and the second column contains the values of the arrays.


    */

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
float *readData(int n);
float get_average(float *, int);
int main(void)
{
    int numStudents = 3;
    float *scores = malloc(sizeof(float) * numStudents);
    scores[0] = 100;
    scores[1] = 95.3;
    scores[2] = 89.7;
    float ave = get_average(scores);
    printf("The average is %f.", ave);
    // 6B Draw what the stack and heap look like here
    free(scores);
}
float get_average(float *d1, int size)
{
    int data = 0;
    for (int j = 0; j < size; j++)
    {
        data = data + d1[j];
    }
    // 6A Draw what the stack and the heap look like here
    return data / size;
}
