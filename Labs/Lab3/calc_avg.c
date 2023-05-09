#include <stdio.h>
#include <stdlib.h>

float get_average(float A[], int size);

int main(int argc, char *argv[]){

    int numVals = 0;                // store number of data values

    printf("How many values?\n");   // Prompt user for number of values
    scanf(" %d", &numVals);         // Get number of values

    float data[numVals];        // create array to store values

    printf("Input values\n");
    for (int i = 0; i < numVals; i++){
        scanf(" %f", &data[i]);
    }

    printf("Your values are: ");
    for (int i = 0; i < numVals; i++){
        printf("%7.2f ", data[i]);
    }
    printf("\n");

    float thisAv = get_average(data, numVals);
    printf("Your average is %6.2f\n", thisAv);
}

float get_average(float A[], int size){ // calculate average of array
    float total = 0;
    for (int i = 0; i < size; i ++ ){ // sum all values
        total = total + A[i];
    }
    return total/(float)size; // return average
}

void* readData(char* filename, int size){
    FILE* fp = fopen(filename, "r"); // open file for reading
    if (fp == NULL){ // check if file opened
        printf("Error opening file.");
    }

    float* data = malloc(sizeof(float) * size); // allocate memory for data
    for (int i = 0; i < size; i++){ // read data into array
        fscanf(fp, "%f", &data[i]); 
    }
    fclose(fp);
    return data;
}