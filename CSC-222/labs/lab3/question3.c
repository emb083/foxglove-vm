#include <stdio.h>

int main(){
    int input = 0;

    printf("Enter a negative value at any point to quit.\n");

    printf("Enter an integer: ");
    scanf("%d", &input);

    while (input >= 0){
        printf("Binary equivalent: ");
        int start = 0;
        for (int i=31; i>=0; i--){
            int k = input >> i;
            if (k & 1){
                printf("1");
                if (start == 0){
                    start = 1;
                }
            } else {
                if (start != 0){
                    printf("0");
                }
            }
        }
        
        printf("\nEnter an integer: ");
        scanf("%d", &input);
    }
    printf("Bye.\n");
}