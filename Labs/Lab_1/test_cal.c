#include <stdio.h>

// function prototypes
int printMonthName(int, int);

int main(void){

    int year = 2024;
    int num_days;
    // loop over all months
    for (int i = 0; i < 12; i ++){
        // call printMonthName for each month
        num_days = printMonthName(year, i);
        printf("This month has %d days\n", num_days);
    }
    return 0;
}

/*********************************************************************
* int printMonthName(int year, int month)
*
* Prints the month name and year to the terminal 
*
* Input:
*	year: the year being printed
*	month: the month to be printed (0 indexed)
*
* Returns: The number of days in this month
*
* Output: Prints the month name and year to the terminal
*
*********************************************************************/	
int printMonthName(int year, int month){
    switch (month)
    {
    case 0:
        printf("January %d\n", year);
        return 31;
        break;
    case 1:
        printf("February %d\n", year);
        if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
        {
            return 29;
        } else return 28;
        break;
    case 2:
        printf("March %d\n", year);
        return 31;
        break;
    case 3:
        printf("April %d\n", year);
        return 30;
        break;
    case 4:
        printf("May %d\n", year);
        return 31;
        break;
    case 5:
        printf("June %d\n", year);
        return 30;
        break;
    case 6:
        printf("July %d\n", year);
        return 31;
        break;
    case 7:
        printf("August %d\n", year);
        return 31;
        break;
    case 8:
        printf("September %d\n", year);
        return 30;
        break;
    case 9:
        printf("October %d\n", year);
        return 31;
        break;
    case 10:
        printf("November %d\n", year);
        return 30;
        break;
    case 11:
        printf("December %d\n", year);
        return 31;
        break;
    default:
        return 0;
        break;
    }
}