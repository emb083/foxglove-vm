#include <stdio.h>
#include <string.h>

int main(){
    // for arrays of strings, we make 2d character arrays
    // format is myArray[numberOfItems][LengthOfItem]

    char strArray[5][10] = {"bread", "milk", "eggs"};
    strcpy(strArray[0], "bacon");
    printf("%s\n", strArray[0]);
    printf("%s\n", strArray[1]);

    printf("length: %lu\n", sizeof(strArray[0])/sizeof(char));
    // why 10?
    for (int i=0; i<(sizeof(strArray[0])/sizeof(char)); i++){
        printf("%c\n", strArray[0][i]);
    }
}