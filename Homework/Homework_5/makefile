matrix_calc: matrix_calc.o matrix_math.o
	gcc -g -Wall matrix_calc.o matrix_math.o -lm -o matrixCalc

matrix_math.o: matrix_math.h matrix_math.c
	gcc -g -Wall -c matrix_math.c

matrix_calc.o: matrix_math.h matrix_calc.c
	gcc -g -Wall -c matrix_calc.c

clean:
	del -f matrix_calc.o matrix_math.o matrixCalc

all: matrix_calc