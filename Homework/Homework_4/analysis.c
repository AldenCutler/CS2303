#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define ITEMS 51

int main(int argc, char* argv[]){

    // allocate arrays to store 6 months of data
    int month_data[ITEMS][argc];
    
    // initialize month_data to zeros
    for (int i = 0; i < argc; i ++){
        for (int j = 0; j < ITEMS; j++){
            month_data[j][i] = 0; 
        }
    }

    // initialize first column to item numbers
    for (int i = 0; i < ITEMS; i++){
        month_data[i][0] = i;
    }

    int new_item;
    float cost;

    //loop over all months
    for (int i = 1; i < argc; i++){
        FILE* f1 = fopen(argv[i], "r"); // open the file

        // load sales data
        while (fscanf(f1, "%d %f", &new_item, &cost) != EOF){
            month_data[new_item][i] = month_data[new_item][i] + 1;
        }
        fclose(f1); // close the file
    } // end loop over months

    // load price data
    float* costs = readCosts(ITEMS);
    float* purch = readPurch(ITEMS);

    // call all 3 functions here
    get_totals(ITEMS, argc, month_data);
    get_profits(ITEMS, argc, month_data, costs, purch);
    top_earner(ITEMS, argc, month_data, costs, purch);

    // free the memory allocated to the costs and purch arrays
    free(costs);
    free(purch);
}