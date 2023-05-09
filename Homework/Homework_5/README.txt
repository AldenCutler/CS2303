This program takes three command line arguments, two are the input files, and the last is the type of calculation.
From the two input files, both of which contain matrices, the program will either calculate the sum, difference, or
average of the two matrices. 

To compile:
make
(if this doesn't work, try this instead:)
mingw32-make

To run:
./matrixCalc input.txt input2.txt type
where type is either 'a' for add, 's' for subtract, or 'n' for average.