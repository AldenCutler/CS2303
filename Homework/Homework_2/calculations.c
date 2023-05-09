#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


/********************************************************
*   float overall_revenue(FILE *f1)
*   calculates the overall revenue of the coffee shop
*   
*   Input:
*       f1 - file pointer to the input file
*   Returns:
*       revenue - the overall revenue of the coffee shop
*   Output:
*       prints the overall revenue of the coffee shop
*   Calls:
*       None
*********************************************************/
float overall_revenue(FILE *f1){
    int itemNum;
    float price;
    float revenue = 0;

    while (fscanf(f1, "%d   %f ", &itemNum, &price) != EOF){
        if (itemNum != 0){
            revenue += price;
        }
    }

    printf("%g\n", revenue);
    return revenue;
}

/********************************************************
*   float balance(FILE *f1)
*   calculates the amount of money in the register of the coffee shop
*   
*   Input:
*       f1 - file pointer to the input file
*   Returns:
*       balance - the amount of money in the register
*   Output:
*       prints the amount of money in the register
*   Calls:
*       None
*********************************************************/
float balance(FILE *f1){
    int itemNum;
    float price;
    float balance = 0;
    
    while (fscanf(f1, "%d     %f  ", &itemNum, &price) != EOF){
        balance += price;
    }
    
    printf("%g\n", balance);
    return balance;
}

/********************************************************
*   int tally(FILE *f1, int itemNum)
*   counts the number of times an item is sold and calculates the revenue of that particular item
*   
*   Input:
*       f1 - file pointer to the input file
*       itemNum - the item number to be analyzed
*   Returns:
*       count - the number of times the item is sold
*   Output:
*       prints the number of times the item is sold and the revenue of that item to an output file specified by the user
*   Calls:
*       None
*********************************************************/
int tally(FILE *f1, int itemNum){
    int count = 0;
    int itemID = itemNum;
    float price;
    float revenue = 0;
    char * output;
    char appendOrOverwrite;
    FILE * f2;

    printf("What is the output file?\n");
    scanf(" %ms", &output);

    printf("Enter A for Append or O for over-write.\n");
    scanf(" %c", &appendOrOverwrite);
    
    if (appendOrOverwrite == 'A'){
        f2 = fopen(output, "a");
    } else if (appendOrOverwrite == 'O'){
        f2 = fopen(output, "w");
    } else {
        printf("Invalid input.");
        return 0;
    }

    while (fscanf(f1, "%d %f  ", &itemNum, &price) != EOF){
        if (itemID == itemNum){
            count++;
            revenue = revenue + price;
        }
    }
    
    fprintf(f2, "%3d %3d\n", itemID, count);
    fclose(f1);
    fclose(f2);

    return count;
}