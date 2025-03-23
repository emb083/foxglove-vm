#include <stdio.h>

int main(){
    char name[25];
    int age;

    printf("What is your name? ");
    scanf("%s", name); // plugs input into memory location

    printf("What is your age? ");
    scanf("%d", &age); // MUST be a memory location

    printf("Hi, %s! You are %d years old.\n", name, age);

    //NOTE: This methods cannot handle spaces, as that denotes separate arguments.
}