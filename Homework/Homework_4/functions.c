#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define ITEMS 51

// ----------------------------------------------

float* readCosts(int numItems){
    float* costs = malloc(numItems * sizeof(float)); // allocate memory for costs

    FILE* f1 = fopen("Costs.txt", "r"); // open the file
    
    for (int i = 0; i < numItems; i++){ // loop over the items
        fscanf(f1, "%*d %*f %f", &costs[i+1]); // read the cost of the item
    }
    fclose(f1); // close the file

    return costs; // return the array of costs
}

float* readPurch(int numItems){
    float* purch = malloc(numItems * sizeof(float)); // allocate memory for purch
    FILE* f1 = fopen("Costs.txt", "r"); // open the file
    for (int i = 0; i < numItems; i++){ // loop over the items
        fscanf(f1, "%*d %f %*f", &purch[i+1]); // read the purchase price of the item
    }
    fclose(f1); // close the file
    return purch; // return the array of purchase prices
}

// ----------------------------------------------


void get_totals(int row, int column, int data[][column]){
    // initialize variables    
    FILE * f1 = fopen("Total_sales.txt", "w");

    // loop over the rows
    for (int i = 1; i < row; i++){
        int count = 0; // count is the total number of items sold
        for (int j = 1; j < column; j++){
            count = count + data[i][j]; // add the sum of the rest of the row to the count
        }
        fprintf(f1, "%5d %5d\n", i, count); // print the item number and the number of items sold to the file
    }

    fclose(f1); // close the file
}


void get_profits(int row, int column, int month_data[][column], float costs[], float purch[]){
    // initialize variables
    FILE *f1 = fopen("Profits.txt", "w");
    float cost, sales = 0;
    
    // print the header of the file
    fprintf(f1, "%s", "    Item       #   Sales    Cost Revenue\n");

    // loop over the rows
    for (int i = 1; i < row; i++){
        int item = month_data[i][0]; // item is the item number
        int count = 0; // count is the total number of items sold
        for (int j = 1; j < column; j++){
            count = count + month_data[i][j]; // add the sum of the rest of the row to the count
        }

        cost = count * costs[i]; // calculate the cost of the item
        sales = count * purch[i]; // calculate the sales of the item

        fprintf(f1, "%8d%8d%8.2f%8.2f%8.2f\n", i, count, sales, cost, sales-cost); // print the item number, the number of items sold, the cost, the sales, and the profit to the file    }
    }
    fclose(f1); // close the file
    
}


void top_earner(int rows, int columns, int month_data[][columns], float costs[], float purch[]){
    // initialize variables
    FILE * f1 = fopen("Top_earners.txt", "w"); // open the file
    int data[rows][2]; // data is a 2D array of the item number and the revenue
    float revenue = 0; // revenue is the revenue of the item
    int numSold; // numSold is the number of items sold
    int item; // item is the item number
    float revenueArray[rows]; // revenueArray is an array of the revenue of each item


    // print the header of the file
    fprintf(f1,"Item   #  Revenue\n");

    // calculate the revenue of each item and store it in revenueArray
    for (int i = 1; i < rows; i++){
        item = month_data[i][0]; // item is the item number
        numSold = 0; // reset numSold
        for (int j = 1; j < columns; j++){
            numSold = numSold + month_data[i][j]; // add the sum of the rest of the row to the count
        }

        /*
        In case the for loop doesn't work, use this instead:
        numSold = month_data[i][1] + month_data[i][2] + month_data[i][3] + month_data[i][4] + month_data[i][5] + month_data[i][6]
        */

        data[i][0] = item;
        data[i][1] = numSold;
        revenue = numSold * (purch[i] - costs[i]); // calculate the revenue of the item
        revenueArray[i] = revenue; // store the revenue in revenueArray
    }

    // print the top 10 earners to the file
    for (int i = 0; i < 10; i++){
        int max = 0; // max is the index of the item with the highest revenue
        for (int j = 0; j < rows; j++){
            if (revenueArray[j] > revenueArray[max]){
                max = j;
            }
        }
        fprintf(f1, "%5d%5d%8.2f\n", data[max][0], data[max][1], revenueArray[max]); // print the item number, the number of items sold, and the revenue to the file
        revenueArray[max] = 0; // set the revenue of the item to 0 so it won't be printed again
    }
    fclose(f1); // close the file

}