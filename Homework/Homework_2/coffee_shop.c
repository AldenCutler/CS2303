#include <stdio.h>
#include "calculations.h"


/********************************************************
*   main(void)
*   asks user for input file and which program to run
*   
*   Input:
*       None
*   Returns:
*       0
*   Output:
*       Depending on what calculation the user requests, either:
*           - overall revenue
*           - register balance
*           - sales for an item
*   Calls:
*       overall_revenue(FILE *f1)
*       balance(FILE *f1)
*       tally(FILE *f1, int itemNum)
*********************************************************/
int main(void){

    int taskNum;
    char fileName[100];
    FILE * inputFile;

    printf("Which program would you like to run: (1) Calculate overall revenue, (2) Calculate register balance, or (3) Calculate sales for an item.\n");
    scanf("%d", &taskNum);

    if (taskNum == 1 || taskNum == 2 || taskNum == 3){
        printf("Please enter an input file:\n");
        scanf("%s", fileName);
        inputFile = fopen(fileName, "r");
        switch (taskNum)
        {
        case 1:
            overall_revenue(inputFile);
            break;
        case 2:
            balance(inputFile);
            break;
        case 3:
            int itemNum;
            printf("Which item to analyze?\n");
            scanf("%d", &itemNum);
            tally(inputFile, itemNum);
            break;
        default:
            break;
        }
    } else printf("This option is not valid.");
    
    return 0;
}
