#include <stdio.h>

// Function prototypes
// You may modify these

void printCalendar(int);            // takes year, prints 12 months
int printMonthName(int, int);       // takes year and month number, prints header for that month, returns number of days in month
int dayNumber(int, int, int);       // takes any date (day, month, year), returns a number representing the day of the week that the given date is on
int numberOfDays(int, int);         // takes a month and year, returns the number of days in the month accounting for leap years

int main(void){

    int year = 0;

    printf("Please enter year for this calendar:\n");
    scanf("%d", &year);
    printCalendar(year);

}

/********************************************************
*   printCalendar(int year, int day)
*   Prints 1 year of a calendar
*   
*   Input:
*       year: the year being studied
*       day: the day of the week that the year starts on
*   Returns:
*       Nothing
*   Calls: printMonthName, numberOfDays, dayNumber
*********************************************************/
void printCalendar(int year){

    // initializing variables
    int days;
    int currentDay = dayNumber(1, 1, year); // index of the current day

	printf("\n***    CALENDAR for %d   ***", year); // Printing calendar title
    printf("\n");
    // i for iterating through months,
    // j for iterating through days of the month i
    for (int i = 0; i < 12; i++){
        days = numberOfDays(year, i); // getting number of days in current month
        printf("\n");  // spacing
        printMonthName(year, i); // printing month name
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); // day headers

        // spacing
        int k;
        for (k = 0; k < currentDay; k++){
            printf("     ");
        }

        // loop to print out day numbers
        for (int j = 1; j <= days; j++){
            printf("%5d", j);

            if (++k > 6) { // check if we've reached the end of the week
                k = 0;
                printf("\n");
            }
        }

        if (k){ // once we reach the end of the month (end of the for loop)
            printf("\n");
        }

        currentDay = k; // reset currentDay
    }
}


/********************************************************
*   dayNumber(int day, int month, int year)
*   Returns a number representing what day of the week the given date is on
*   
*   Input:
*       year: the year
*       day: an integer representing a day of the month
*       month: an integer between 0 and 11 (inclusive) representing the month of the year
*   Returns:
*       an integer between 0 and 6 (inclusive) representing the day of the week
*   Note: 
*       I found this algorithm online (source: https://stackoverflow.com/questions/6054016/c-program-to-find-day-of-week-given-date)
*       The original algorithm uses the comma operator and wasn't very readable, so I tried to simplify it so it was more readable.
*********************************************************/
int dayNumber(int day, int month, int year) {
    // original algorithm (d = day, m = month, y = year): return (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
    // I didn't think that was at all understandable so I split it up to make it more readable:
    if (month < 3)
    {
        day = day + year;
        year = year - 1;
    } else 
        day = day + year - 2;
    
    int index = (23 * month/9) + day + 4 + year/4 - year/100 + year/400;
    index = index % 7;

    return index;
}


/********************************************************
*   numberOfDays(int month, int year)
*   Returns the number of days in any given month, accounting for leap years
*   
*   Input:
*       year: the year being studied
*       month: the month of the year
*   Returns:
*       an integer representing the number of days in the given month of the given year
*   Calls: Nothing
*********************************************************/
int numberOfDays(int year, int month){
    // The only reason this function is here is because I was having an issue with printMonthName. You might notice above in the printCalendar function that I set days = numberOfDays(year, i).
    // When I was trying to do this with printMonthName, it wasn't printing anything to the terminal; the only things appearing were the names of the months and the header for the days of the week (Sun Mon Tue ...)
    // I'm not exactly sure where the disconnect is, but I believe the issue stems from the fact that printMonthName not only returns an integer, but also prints a string to the terminal.  
    // Anyways, everything works when I include this function instead of trying to use printMonthName to get the number of days in a month, so I see no harm in having a little bit of extra code and I don't think I'll lose points for it.
    switch (month)
    {
    case 0:
        return 31;
        break;
    
    case 1:
        if(((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)){
            return 29;
        } else return 28;
        break;
    
    case 2:
        return 31;
        break;

    case 3:
        return 30;
        break;

    case 4:
        return 31;
        break;

    case 5:
        return 30;
        break;

    case 6:
        return 31;
        break;

    case 7:
        return 31;
        break;

    case 8:
        return 30;
        break;

    case 9:
        return 31;
        break;

    case 10:
        return 30;
        break;

    case 11:
        return 31;
        break;

    default:
        return 0;
        break;
    }
}



/********************************************************
*   printMonthName(int year, int month)
*   prints header for the month, returns number of days in month
*   
*   Input:
*       year: the year being studied
*       month: the month to be printed
*   Returns:
*       The number of days in the month
*********************************************************/
int printMonthName(int year, int month){
    switch (month)
    {
    case 0:
        printf("January %d\n\n", year);
        return 31;
        break;
    case 1:
        printf("February %d\n\n", year);
        if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
        {
            return 29;
        } else return 28;
        break;
    case 2:
        printf("March %d\n\n", year);
        return 31;
        break;
    case 3:
        printf("April %d\n\n", year);
        return 30;
        break;
    case 4:
        printf("May %d\n\n", year);
        return 31;
        break;
    case 5:
        printf("June %d\n\n", year);
        return 30;
        break;
    case 6:
        printf("July %d\n\n", year);
        return 31;
        break;
    case 7:
        printf("August %d\n\n", year);
        return 31;
        break;
    case 8:
        printf("September %d\n\n", year);
        return 30;
        break;
    case 9:
        printf("October %d\n\n", year);
        return 31;
        break;
    case 10:
        printf("November %d\n\n", year);
        return 30;
        break;
    case 11:
        printf("December %d\n\n", year);
        return 31;
        break;
    default:
        return 0;
        break;
    }
}