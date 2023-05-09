#include <stdlib.h>
#include <stdio.h>
#include "matrix_math.h"

struct matrix{
    int size;
    float *data;
};


/*
    * Function: add
    * --------------------
    *  Calculates the sum of two matrices
    *
    *  m1: pointer to the first matrix
    *  m2: pointer to the second matrix
    *
    *  returns: pointer to the sum matrix
*/
struct matrix * add(struct matrix *m1, struct matrix *m2){
    
    struct matrix *sum = malloc(sizeof(struct matrix)); // allocate memory for the sum matrix
    sum->size = m1->size; // set the size of the sum matrix
    sum->data = malloc(sizeof(float) * m1->size); // allocate memory for the data of the sum matrix
    
    for (int i = 0; i < m1->size; i++){ // add the data of the two matrices
        sum->data[i] = m1->data[i] + m2->data[i];
    }
    
    return sum; // return the sum
}

/*
    * Function: sub
    * --------------------
    *  Calculates the difference of two matrices
    *
    *  m1: pointer to the first matrix
    *  m2: pointer to the second matrix
    *
    *  returns: pointer to the difference matrix
*/
struct matrix * sub(struct matrix *m1, struct matrix *m2){

    struct matrix *diff = malloc(sizeof(struct matrix)); // allocate memory for the difference matrix
    diff->size = m1->size; // set the size of the difference matrix
    diff->data = malloc(sizeof(float) * m1->size); // allocate memory for the data of the difference matrix

    for (int i = 0; i < m1->size; i++){ // subtract the data of the two matrices
        diff->data[i] = m1->data[i] - m2->data[i];
    }

    return diff; // return the difference matrix
}

/*
    * Function: avg
    * --------------------
    *  Calculates the average of two matrices
    *
    *  m1: pointer to the first matrix
    *  m2: pointer to the second matrix
    *
    *  returns: pointer to the average matrix
*/
struct matrix * avg(struct matrix *m1, struct matrix *m2){

    struct matrix *avg = malloc(sizeof(struct matrix)); // allocate memory for the average matrix
    avg->size = m1->size; // set the size of the average matrix
    avg->data = malloc(sizeof(float) * m1->size); // allocate memory for the data of the average matrix

    for (int i = 0; i < m1->size; i++){ // average the data of the two matrices
        avg->data[i] = (m1->data[i] + m2->data[i]) / 2;
    }

    return avg; // return the average matrix
}