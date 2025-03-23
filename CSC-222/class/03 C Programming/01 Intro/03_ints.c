#include <stdio.h>

int main(){
    // int
    //  - typically 4 bytes on most 34 and 64 bit machines
    //  - 4 bytes = 4 sets of eight 0s and 1s
    //  - 00000000 00000000 00000000 00000001

    printf("\nints:\n");
    int w = 10;

    printf("w = %d\n", w);
    printf("The size of an int is %lu bytes\n", sizeof(w));


    // short int
    //  - typically 2 bytes on most 32 bit and 64 bit machines
    //  - 2 sets of eight 0s and 1s

    printf("\nshort int:\n");
    short x = 20;
    printf("x = %d\n", x);
    printf("The size of a short int is %lu bytes\n", sizeof(x));


    // long int
    //  - typically 8 bytes

    printf("\nlong int:\n");
    long y = 20;
    printf("y = %ld\n", y);
    printf("The size of a long int is %lu bytes\n", sizeof(y));


    // long long int
    //  - typically 8 bytes
    
    printf("\nlong long int:\n");
    long long int z = 20;
    printf("z = %lld\n", z);
    printf("The size of a long long int is %lu bytes\n", sizeof(z));


    // unsigned versions of the above exist also
    //  - for unsigned versions, you cannot represent negative values
    printf("\nunsigned ints\n");
    unsigned int u1 = 20;
    unsigned int u2 = -20;
    printf("u1 = %u\n", u1);
    printf("u2 = %u\n", u2);
}