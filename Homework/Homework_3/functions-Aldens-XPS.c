#include <stdio.h>
#include <stdlib.h>

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
void get_totals(int data[][7], int row, int col)
{
    
    // FILE *output_file = fopen("Total_sales.txt", "w");
    // for (int i = 0; i < col; i++)
    // {
    //     int count = 0;
    //     int item = data[i][0];
    //     for (int j = 1; j < row; j++)
    //     {
    //         count = count + data[i][j];
    //     }
    //     fprintf(output_file, "%2d%7d\n", item, count);
    // }
    // fclose(output_file);



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
void get_profits(int data[][7], int row, int col, float data_cp[][2])
{
//     FILE *output_file = fopen("Profits.txt", "w");
//     float cost = 0.0;
//     float sales = 0.0;
//     fprintf(output_file, "%s", "    Item       #   Sales    Cost Revenue\n");
//     for(int i = 1; i < col; i++)
//     {
//         int count = 0;
//         int item = data[i][0];
//         for (int j = 1; j < row; j++)
//         {
//             count = count + data[i][j];
//         }

//         cost = data_cp[item][0] * count;
//         sales = data_cp[item][1] * count;

//         fprintf(output_file, "%8d%8d%8.2f%8.2f%8.2f\n", item, count, cost, sales, (cost - sales));
//     }
//     fclose(output_file);
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
    FILE *f1 = fopen("Top_earners.txt", "w");
    float cost = 0;
    float sales = 0;
    float revenue = 0;
    float top_earners[10][2];

    // initialize top_earners to zeros
    for (int i = 0; i < 10; i++){
        top_earners[i][0] = 0;
        top_earners[i][1] = 0;
    }

    // loop over all items
    for (int i = 1; i < columns; i++){
        int count = 0;
        int item = month_data[i][0];
        // loop over all months
        for (int j = 1; j < rows; j++){
            count = count + month_data[i][j];
        }
        // calculate cost, sales, and revenue
        cost = money[item][0] * count;
        sales = money[item][1] * count;
        revenue = cost - sales;

        // loop over top_earners
        for (int k = 0; k < 10; k++){
            // if revenue is greater than the current top_earner, replace it
            if (revenue > top_earners[k][1]){
                top_earners[k][0] = item;
                top_earners[k][1] = revenue;
                break;
            }
        }
    }

    // print top_earners to file
    for (int i = 0; i < 10; i++)
    {
        fprintf(f1, "%8.0f%8.2f\n", top_earners[i][0], top_earners[i][1]);
    }
    
    
}