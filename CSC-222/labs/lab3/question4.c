#include <stdio.h>

#define LITER 3.785
#define KM 1.609

int main(){

    float input_m = 0;
    float input_g = 0;

    printf("Enter number of miles travelled: ");
    scanf("%f", &input_m);

    printf("Enter number of gallons of gas used: ");
    scanf("%f", &input_g);

    printf("Mile-per-gallon: %.2f\n", input_m/input_g);
    printf("Liters-per-100-km: %.1f\n", (input_g*LITER)/(input_m*KM)*100);
}