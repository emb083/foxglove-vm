#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){

    // Bitwise Operators
    //      recall: ints are 32 bits (4 bytes)
    //      00000000 00000000 00000000 00001010 = 10 in decimal

    unsigned int u = 10;
    unsigned int v = 15;

    // print u as bits
    printf("u = ");
    for (int i = sizeof(int)*8-1; i>=0; i--){
        printf("%u", (u >> i) & 1);
        if (i%8 == 0){
            printf(" ");
        }
    }
    printf("\n");


    // bitwise and  &
    unsigned int res = u & v;
    /*
        u       1010
        v       1111
        res     1010 = 10 in decimal
    */
    printf("Ex 1: %d\n", res);

    // bitwise or   |
    unsigned int res2 = u | v;
    /*
        u       1010
        v       1111
        res     1111 = 15 in decimal 
    */
    printf("Ex 2: %d\n", res);

    // bitwise not/flip operator/complementing   ~
    unsigned int res3 = ~u;
    /*
        u   00000000 00000000 00000000 00001010
        ~u  11111111 11111111 11111111 11110101 = 4,294,967,285 in decimal
    */
    printf("Ex 3: %u\n", res3);

    // bitwise xor  ^
    unsigned int res4 = u ^ v;
    /*
        u      1010
        v      1111
        res4   0101 = 5 in decimal
    */
    printf("Ex 4: %u\n", res4);

    // Right Shift  >>
    unsigned int res5 = v >> 3;
    /*
        Shift every bit over a certain amount of places
        15 >> 3
        1111 >> 3   =>  0001 = 1 (decimal)
    */
    printf("Ex 5: %u\n", res5);

    // Left Shift   <<
    unsigned int res6 = v << 2;
    /*
        15 << 2
        1111 << 2   =>  111100  = 60 (decimal)
    */
    printf("Ex 6: %u\n", res6);

    // Shifting can be used for power of 2 multiplication and division:
    // note: pow() needs #include <math.h> and, on some systems, compile with -lm

    // Left shift for power of 2 multiplication
    //      u << k == u * pow(2, k)
    int h = 3;
    int k = 2;
    printf("%d\n", h << k);
    printf("%lf\n", h * pow(2, k));

    // Right shift for power of 2 division
    //      u >> k == u / pow(2, k)
    int h2 = 2500;
    int k2 = 3;
    printf("%d\n", h2 << k2);
    printf("%lf\n", h2 * pow(2, k2));

    return 0;
}