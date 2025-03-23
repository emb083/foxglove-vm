#include <stdio.h>
#include <unistd.h>

int main(){
    printf("This");

    fflush(stdout);

    fork();

    printf("?\n");
    return 0;
}