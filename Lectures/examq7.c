#include <stdio.h>
#include <stdlib.h>

int main(void){
    int numStudents = 5;

    float* scores = readData(numStudents);
    float ave = get_average(scores, numStudents);
    printf("The average is: %f.", ave);

    // draw what the stack and heap look like here

    free(scores); 
}

float* readData(int n){
    float* data = malloc(n * sizeof(float));
    FILE* f1 = fopen("data.txt", "r");
    for (int j = 0; j < n; j++){
        fscanf(f1, "%f", &data[j]);
    }
    return data;
}

float get_average(float* data, int n){
    float sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + data[i];
    }

    // draw what the stack and heap look like here

    return sum / n;
}

// ----------------------------------------------

// LinkedLists

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    float value;
    struct node* next;
};

int main(void){
    Node first; 
    first.value = 0; // initialize the first node with a value of 0
    Node second = {1}; // initialize the second node with a value of 1
    first.next = &second; // assign the address of the second node to the next pointer of the first node
    second.next = NULL; // assign NULL to the next pointer of the second node
    return 0;
}