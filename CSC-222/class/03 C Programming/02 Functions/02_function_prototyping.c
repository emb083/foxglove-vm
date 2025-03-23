#include <stdio.h>

// function prototyping
int addOne(int);

//main
int main(){
    int num = 10;
    int result = addOne(num);
    printf("%d\n", result);
}

// function definitions
int addOne(int value){
    return value + 1;
}