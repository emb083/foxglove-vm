#include <stdio.h>

int main(){
    // a pointer is a reference to a location in memory
    // use * when declaring pointeres
    // still use the data type of the data that the pointer corresponds to
    // use & to get the memory address of a variable

    int faveNum = 42;
    int *faveNumPtr = &faveNum; // get the memory address and give it a reference
    // read & as "address at"

    printf("FaveNum: %d\nLoc: %p\n", faveNum, faveNumPtr);

    // The * symbol is also the indirection operator
    // Indirection allows us to access the value associated with a pointer
    printf("Fave Num: %d\n", *faveNumPtr);
}