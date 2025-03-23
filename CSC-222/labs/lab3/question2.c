#include <stdio.h>
#include <math.h>

#define DAY 24
#define HOUR 60
#define MINUTE 60

int main(){
    int input = 0;

    printf("Enter a negative value at any point to quit.\n");

    printf("Enter the number of seconds to convert: ");
    scanf("%d", &input);

    while (input >= 0){
        int seconds = input%MINUTE;
        int minutes = (int)floor(input/MINUTE)%HOUR;
        int hours = (int)floor(floor(input/MINUTE)/HOUR)%DAY;
        int days = (int)floor(floor(floor(input/MINUTE)/HOUR)/DAY);

        int timeArray[] = {days, hours, minutes, seconds};
        for (int i=0; i<4; i++){
            if (timeArray[i]==0){
                continue;
            } else {
                switch (i) {
                    case 0:
                        printf("%dd ", timeArray[i]);
                        printf("%dh ", timeArray[i+1]);
                        printf("%dm ", timeArray[i+2]);
                        printf("%ds\n", timeArray[i+3]);
                        break;
                    case 1:
                        printf("%dh ", timeArray[i]);
                        printf("%dm ", timeArray[i+1]);
                        printf("%ds\n", timeArray[i+2]);
                        break;
                    case 2:
                        printf("%dm ", timeArray[i]);
                        printf("%ds\n", timeArray[i+1]);
                        break;
                    case 3:
                        printf("%ds\n", timeArray[i]);
                        break;
                }
                break;
            }
        }
        printf("Enter the number of seconds to convert: ");
        scanf("%d", &input);
    }
    printf("Done.\n");
}