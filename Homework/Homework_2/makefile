
coffee_shop: calculations.o coffee_shop.o
	gcc -g -Wall coffee_shop.o calculations.o -lm -o sales.exe 

calculations.o: calculations.h calculations.c
	gcc -g -Wall -c calculations.c

coffee_shop.o: calculations.h coffee_shop.c
	gcc -g -Wall -c coffee_shop.c

clean:
	del -f coffee_shop.o calculations.o coffee_shop

all: coffee_shop