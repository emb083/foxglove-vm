#include <stdio.h>
#include <string.h>

int main(){
    // strings are character arrays
    // strings always terminate with the null character
    // the null character is not 'null' but is '\0'

    // Ex:
    char greeting[] = "Hi, how are you?";
    printf("%s\n", greeting);

    // Ex: Getting the size of a string
    printf("length: %lu\n", sizeof(greeting)/sizeof(char));
    // Anytime you print a string, a null character is appended to the end of it.
    // Thus, the size of this string is 17, not 16!

    printf("helper func length: %lu\n", strlen(greeting));
    // automatically substracts one to not count the null
    // if you don't have access to the library, you could just do this yourself

    
    // Ex: Comparing strings
    char hello[] = "hello";
    char you[] = "you";

    // if strcmp returns 0, then the strings are the same
    if (strcmp(hello, you) == 0){
        printf("twinsies! :D\n");
    } else {
        printf("imposter!!! D:<\n");
    }


    // Ex: Reassigning string identifiers with strcpy

    strcpy(hello, "you");
    if (strcmp(hello, you) == 0){
        printf("twinsies! :D\n");
    } else {
        printf("imposter!!! D:<\n");
    }
}