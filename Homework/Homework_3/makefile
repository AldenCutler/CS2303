
analysis: analysis.o functions.o
	gcc -g -Wall analysis.o functions.o -lm -o analysis.exe 

functions.o: functions.h functions.c
	gcc -g -Wall -c functions.c

analysis.o: functions.h analysis.c
	gcc -g -Wall -c analysis.c

clean:
	del -f analysis.o functions.o analysis

all: analysis