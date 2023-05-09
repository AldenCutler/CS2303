#include <stdio.h>

int main(void){
    for (float n = 1; n <= 20; n++)
    {
        float x = 5/n;
        printf("%5.3f\n", x);   
    }   
}

float calculateRevenue(float price, float quantity){
    float revenue = price * quantity;
    return revenue;
}

float calculateProfit(float price, float quantity){
    float profit = calculateRevenue(price, quantity) - (price * quantity);
    return profit;
}

// copilot is sick
