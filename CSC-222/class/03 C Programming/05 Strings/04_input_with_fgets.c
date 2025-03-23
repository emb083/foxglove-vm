#include <stdio.h>

int main(){
    // fgets stands for file-get-string
    // fgets allows us to store text with spaces in it (unlike scanf)
    // warning: fgets ands a newline at the end of the string

    char aLineOfText[100];
    printf("Type a sentence: ");
    fgets(aLineOfText, 100, stdin);

    printf("You said: %s", aLineOfText);
}