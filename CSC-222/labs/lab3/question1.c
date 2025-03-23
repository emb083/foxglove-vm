#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc < 3){
        printf("Must provide at least 2 arguments.");
    } else if (argc > 7) {
        printf("Must provide at most 6 arguments.");
    } else {
        for (int i=1; i<argc; i++){
            if (i%2!=0){
                printf("%c ", argv[i][0]);
            } else {
                printf("%c ", argv[i][1]);
            }
        }
    }
}