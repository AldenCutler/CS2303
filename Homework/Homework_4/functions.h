#include <stdio.h>

void get_totals(int rows, int col, int array[][col]);
void get_profits(int rows, int col, int array[][col], float costs[], float purch[]);
void top_earner(int rows, int col, int array[][col], float costs[], float purch[]);

float* readCosts(int);
float* readPurch(int);