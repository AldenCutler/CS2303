#include <stdio.h>
#include <stdlib.h>

#define ITEMS 51

void get_totals(int[][7], int, int);
void get_profits(int[][7], int, int, float[][2]); 
void top_earner(int[][7], int, int, float[][2]);


/*
    * Function: get_totals
    * --------------------
    *  Calculates the total sales for each item
    *
    *  month_data: 2D array of sales data
    *  rows: number of rows in month_data
    *  columns: number of columns in month_data
    *
    *  returns: void
*/
void get_totals(int data[][7], int row, int column){
    // initialize variables    
    FILE * f1 = fopen("Total_sales.txt", "w");

    for (int i = 0; i < column; i++){ // loop over the columns
        int count = 0; // count is the total number of items sold
        int item = data[i][0]; // item is the item number
        for (int j = 1; j < row; j++){ // loop over the rows
            count += data[i][j]; // add the number of items sold to count
        }
        fprintf(f1, "%2d%7d\n", item, count); // print the item number and the number of items sold to the file
    }
    fclose(f1); // close the file
}




/*
    * Function: get_profits
    * ---------------------
    *  Calculates the total profits for a given month
    *
    *  month_data: 2D array of sales data
    *  rows: number of rows in month_data
    *  columns: number of columns in month_data
    *  money: 2D array of item costs and prices
    *
    *  returns: void
*/
void get_profits(int month_data[][7], int row, int column, float money[][2]){
    // initialize variables
    FILE *f1 = fopen("Profits.txt", "w");
    float cost, sales = 0;
    
    // print the header of the file
    fprintf(f1, "%s", "    Item       #   Sales    Cost Revenue\n");
    
    for(int i = 1; i < column; i++){ // loop over the columns
        int count = 0; // count is the total number of items sold
        int item = month_data[i][0]; // item is the item number
        for (int j = 1; j < row; j++){ // loop over the rows
            count += month_data[i][j]; // add the number of items sold to count
        }

        cost = money[item][0] * count; // cost is the cost of the item * the number of items sold
        sales = money[item][1] * count; // sales is the price of the item * the number of items sold

        fprintf(f1, "%8d%8d%8.2f%8.2f%8.2f\n", item, count, cost, sales, (cost - sales)); // print the item number, the number of items sold, the cost, the sales, and the profit to the file
    }
    fclose(f1); // close the file
}


/*
    * Function: top_earner
    * --------------------
    *  Calculates the 10 top earners with the highest revenue and prints them to a file Top_earners.txt
    *
    *  month_data: 2D array of sales data
    *  rows: number of rows in month_data
    *  columns: number of columns in month_data
    *  money: 2D array of item costs and prices
    *
    *  returns: void
*/
void top_earner(int month_data[][7], int rows, int columns, float money[][2]){
    // initialize variables
    FILE * f1 = fopen("Top_earners.txt", "w"); // open the file
    int data[ITEMS][2]; // data is a 2D array of the item number and the total sales of that item
    float revenueArray[ITEMS]; // revenue is an array of the revenue of each item
    int item; // item is the item number
    int numSold = 0; // numSold is the total number of items sold
    float revenue; // revenue is the revenue of the item

    // print the header of the file
    fprintf(f1,"Item   #  Revenue\n");

    // calculate the revenue of each item
    for (int j = 0; j < ITEMS; j++){
        item = month_data[j][0]; // get the item number

        // I tried using a for-loop to do this calculation, but when I did that, the program would incorrectly calculate the revenue of the items
        numSold = month_data[j][1] + month_data[j][2] + month_data[j][3] + month_data[j][4] + month_data[j][5] + month_data[j][6]; // get the total number of items sold
        
        revenue = (numSold * money[j][0]) - (numSold * money[j][1]); // calculate the revenue of the item
        data[j][0] = item; // store the item number and the total number of items sold in the data array
        data[j][1] = numSold;
        revenueArray[j] = revenue;

    }
    for (int i = 0; i < 10; i++){ // print the top 10 earners
        int k = 0; // k is the index of the item with the highest revenue
        for (int j = 0; j < ITEMS; j++){ 
            if (revenueArray[k] < revenueArray[j]){ // find the item with the highest revenue
                k = j; 
            }
        }
        float topRevenue = revenueArray[k]; // using the index of the item with the highest revenue, get the revenue of that item
        fprintf(f1, "%4d %3d %8.2f \n", data[k][0], data[k][1], topRevenue); // print the item number, total sales, and revenue of the item with the highest revenue
        revenueArray[k] = 0; // set the revenue of the item with the highest revenue to 0 so that it is not printed again
    }
    fclose(f1); // close the file
}