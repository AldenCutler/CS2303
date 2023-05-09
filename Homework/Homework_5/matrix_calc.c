#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"

struct matrix{
    int size;
    float *data;
};


/*
    * Function: deleteMatrix
    * --------------------
    *  Deletes a matrix
    *
    *  m: pointer to the matrix to delete
    *
    *  returns: 0
*/
int deleteMatrix(struct matrix* m){
    free(m->data);
    free(m);
    return 0;
}

/*
    * Function: readMatrix
    * --------------------
    *  Reads in a matrix from a file and stores it in an array
    *
    *  fileName: the name of the file to read from
    *
    *  returns: pointer to the matrix
*/
struct matrix *readMatrix(char *fileName){
    FILE *fp = fopen(fileName, "r");
    
    int size;

    fscanf(fp, "%d", &size);

    struct matrix *m = malloc(sizeof(struct matrix));
    m->size = size; // set the size of the matrix
    m->data = malloc(sizeof(float) * size); // allocate memory for the data

    // read in the data
    for (int i = 0; i < size; i++){
        fscanf(fp, "%f", &m->data[i]);
    }
    fclose(fp);

    return m;
}

int main(int argc, char* argv[]){

    // check that the correct number of arguments were passed
    if (argc != 4){
        printf("Usage: matricCalc <matrix1> <matrix2> <operation>");
        exit(1);
    }

    char type = argv[3][0];

    // read in the matrices
    struct matrix *m1 = readMatrix(argv[1]);
    struct matrix *m2 = readMatrix(argv[2]);

    // check that the matrices are the same size
    if (m1->size != m2->size){
        printf("This math cannot be performed.");
        return 1;
    }

    // perform the operation
    struct matrix *result;
    switch (type){
        case 'a':
            result = add(m1, m2);
            break;
        case 's':
            result = sub(m1, m2);
            break;
        case 'n':
            result = avg(m1, m2);
            break;
        default:
            printf("Invalid operation.");
            return 1;
    }

    // print the result
    for (int i = 0; i < result->size; i++){
        printf("%5.2f ", result->data[i]);
    }

    // free the memory
    deleteMatrix(m1);
    deleteMatrix(m2);
    deleteMatrix(result);
    return 0;
}