#include <stdio.h>

void addStuff(int myArray[], int myArrayLength){
    for (int i=0; i<myArrayLength; i++){
        myArray[i] = i*2;
    }
}

void viewStuff(int *myArray, int myArrayLength){
    for (int i=0; i<myArrayLength; i++){
        printf("The item at index %d is %d.\n", i, myArray[i]);
    }
}

int main(){
    // when we pass arrays into functions, they "decay" to pointers
    // this means we cannot use sizeof() on the array inside a user-defined func
    // often we must pass in the array length as a parameter because of this

    int ages[5];
    size_t length = sizeof(ages)/sizeof(int);

    addStuff(ages, length);
    viewStuff(ages, length);

    return 0;
}