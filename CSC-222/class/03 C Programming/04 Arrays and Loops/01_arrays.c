#include <stdio.h>

int main(){
    // arrays are collections of similar values in continguous memory locations

    int someNums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int moreNums[10]; //create an empty array with size of 10

    printf("Addr: %p\n", someNums); // note: someNums without & is the memory location
    printf("Addr: %p\n", &someNums); // same as line above
    
    printf("Value at i=0: %d\n", someNums[0]);
    printf("Addr at i=0: %p\n", &someNums[0]);

    printf("Addr at i=1: %p\n", &someNums[1]);
    printf("Addr at i=2: %p\n", &someNums[2]);
    printf("Addr at i=3: %p\n", &someNums[3]);

    printf("\n");

    // within the same unit the array was defined,
    // you can use sizeof to get how large it is
    printf("Size: %lu\n", sizeof(someNums));

    // getting the length of the array
    printf("Length: %lu\n", sizeof(someNums)/sizeof(int));
}