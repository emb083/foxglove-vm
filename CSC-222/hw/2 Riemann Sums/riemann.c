#include <stdio.h>
#include <math.h>

// PROTOTYPING

// Function that prints introduction.
void introduction();

// Function that prompts user for information.
//  - Takes in argument for what information the user should provide
//      - a, b, or delta
//  - Prompt, then return data to calling statement
double promptUser(char[]);

// Function that prints accuracy statement
void accuracyWarning();

// Function that evaluates f(x) = 3x^3 - 2x^2
//  - Takes in variable x and returns appropriate f(x)
double evaluateFunction(double);

// Function that calculates Riemann Sum
//  - Takes in 3 arguments:
//      - Lower limit, upper limit, delta
//  - Returns resulting sum to calling statement
double reimannSum(double, double, double);


// MAIN
//  - Calls all other functions
//  - Final print statment occurs here
//      - accuracy of 4 digits after the decimal point
int main(){
    introduction();
    double a = promptUser("a");
    double b = promptUser("b");
    accuracyWarning();
    double delta = promptUser("delta");
    double result = reimannSum(a, b, delta);
    printf("The integral over the provided limits is %.4lf\n", result);

    return 0;
}


// FUNCTION DEFINITIONS

void introduction(){
    printf("This program will calculate the integral of the function\n");
    printf("\t3x^3 - 2x^2\n");
    printf("Between user defined limits: a and b\n");
}

double promptUser(char prompt[]){
    double input;
    printf("What is the value of '%s': ", prompt);
    scanf("%lf", &input);
    return input;
}

void accuracyWarning(){
    printf("The accuracy of this calculation depends on the value of delta that you use.\n");
}

double evaluateFunction(double x){
    // f(x) = 3x^3 - 2x^2
    return (3*pow(x, 3))-(2*(pow(x,2)));
}

double reimannSum(double a, double b, double delta){
    double n = (b-a)/delta;
    double sum = 0;
    for (double i=0; i<n; i++){
        sum += delta*evaluateFunction(a+(delta*i));
    }
    return sum;
}