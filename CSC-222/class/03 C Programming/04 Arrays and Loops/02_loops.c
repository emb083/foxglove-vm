#include <stdio.h>

int main(){
    // arrays to work with
    int nums[] = {1, 2, 3, 4, 5, 6};
    int otherNums[10];

    // while loop
    int counter = 0;
    while (counter < 10){
        otherNums[counter] = counter * 2;
        counter++;
    }

    // for loop
    size_t n = sizeof(nums)/sizeof(int); // get the length of nums
    for (int i=0; i<n; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    // do-while loop
    //  always does the contents of the loop at least once
    int j = 10;
    do {
        printf("%d\n", j);
        j -= 1;
    } while (j > 11);
}