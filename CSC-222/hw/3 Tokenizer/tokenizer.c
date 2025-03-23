// Name: Elia Browning
// Date: 1/28/2025

#include <stdio.h>
#include <string.h>

int main(){
    char input[256];

    while (strcmp(input, "exit\n") != 0){
        printf("$ ");
        fgets(input, 256, stdin);

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0){
            break;
        }

        printf("Line read: %s\n", input);
        printf("Token(s):\n");

        int tokenCount = 0;
        char *tokenPtr = strtok(input, " ");

        while (tokenPtr != NULL) {
            printf(" %s\n", tokenPtr);
            tokenPtr = strtok(NULL, " ");
            tokenCount++;
        }

        printf("%d token(s) read\n\n", tokenCount);

    }

    return 0;
}