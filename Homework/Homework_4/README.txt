This program analyzes past data for a coffee shop and summarizes it in three methods. First, it creates Total_sales.txt that contains
a list of each item and the total number of sales for the item. Second, the program creates Profits.txt that contains the total sales,
total cost, amount earned, and profit for each item. Lastly, the program creates Top_earners.txt which lists the top 10 items with the highest
revenue. The main difference between this program and the previous one is that this one accepts a variable amount of command line arguments
that represent the months to analyze instead of a set 6 months of data. 

To run the progam, first compile by typing into the command line: 
make
(if this doesn't work, type:)
mingw32-make

Then, to run the executable, type:
./analysis.exe month1_data.txt month2_data.txt month3_data.txt ...
where each text file contains the data for a month you want the program to analyze (ex: ./analysis.exe Jan_data.txt Feb_data.txt)

This is my own work, based off my submission for the last homework assignment. I went to a help session to help debug it. 
