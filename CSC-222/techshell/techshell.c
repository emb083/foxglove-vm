// Name: Elia Browning
// Class: CSC 222-002
// Instructor: Josh Coriell
// Date: 2/26/2025

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARRAY_SIZE 25
#define MAX_STRING_SIZE 100
#define TOTAL_SIZE 250

#define DEBUG 0

// Protyping:

// Display current working directory and return user input
char* cmdPrompt();

// Splits string into an array of strings by space delimiter, and returns result
char** tokenizer(char*);

// Process the user input (as a shell command)
struct ShellCommand parseCmdLine(char*);

// Execute a shell command
void executeCmd(struct ShellCommand);

// Write shell command to history
void writeHistory(char*);

struct ShellCommand {
    char cmd[MAX_ARRAY_SIZE];
    int argc;
    char argv[MAX_ARRAY_SIZE][MAX_STRING_SIZE];
};


// MAIN
int main(){
    char* input;
    struct ShellCommand cmd;

    // repeatedly prompt the user for input
    for (;;) {
        // get the user's input
        input = cmdPrompt();

        // write command to history
        writeHistory(input);

        // parse the command line
        cmd = parseCmdLine(input);
        
        // check if command is exit to break loop
        if (strcmp(cmd.cmd, "exit") == 0){
            break;
        }

        // execute the command
        executeCmd(cmd);
    }

    // if loop is broken, exit program
    exit(0);
    return 0;
}


// Function definitions:

char* cmdPrompt(){
    char cwd[1000]; // create buffer to store cwd
    getcwd(cwd, 100); // get current working directory
    char *input = malloc(TOTAL_SIZE); // allocates memory and returns a pointer to it
    printf("%s$ ", cwd); // print prompt
    fgets(input, TOTAL_SIZE, stdin); // grab input

    // remove newline character from fgets
    int len = strlen(input);
    if (input[len-1] == '\n'){
        input[len-1] = 0;
    }

    return input;
}

struct ShellCommand parseCmdLine(char* input){
    struct ShellCommand cmd;

    // split input at space

    int tokenCount = 0; // track number of tokens
    char *tokenPtr = strtok(input, " "); // grab first token

    while (tokenPtr != NULL) {
        strcpy(cmd.argv[tokenCount], tokenPtr); // enter token into cmd.argv
        tokenPtr = strtok(NULL, " "); // grab next token
        tokenCount++;
    }

    strcpy(cmd.argv[tokenCount], "\0"); // set last token to NULL

    strcpy(cmd.cmd, cmd.argv[0]); // set cmd.cmd to first token
    cmd.argc = tokenCount; // set cmd.argc to token count

    return cmd;
}

void executeCmd(struct ShellCommand cmd){
    // take in ShellCommand and inputs into exec

    char *args[cmd.argc + 1]; // instantiate list of args to input into execvp, with an extra space for the final NULL

    // insantiate variables to track I/O redirection
    int inputIndex = 0;
    char inputFile[MAX_STRING_SIZE];
    int outputIndex = 0;
    char outputFile[MAX_STRING_SIZE];
    memset(&inputFile, 0, MAX_STRING_SIZE); // reset memory allocation from any previous iterations
    memset(&outputFile, 0, MAX_STRING_SIZE); // reset memory allocation from any previous iterations

    // copy arguments from cmd.argv into args, checking for I/O redirection
    for (int i=0; i<cmd.argc; i++){

        // check for I/O redirection
        if (strcmp(cmd.argv[i], "<") == 0){ // If input redirection,
            inputIndex = i;
            args[i] = NULL;
        } else if (strcmp(cmd.argv[i], ">") == 0){ // If output redirection,
            if (DEBUG == 1){
                printf("\texecuteCmd: output redirection detected\n");
            }
            outputIndex = i;
            args[i] = NULL;
        }

        if (inputIndex > 0 && i == inputIndex+1){ // If token after input redirection,
            strcpy(inputFile, cmd.argv[i]);
            args[i] = NULL;
        }

        if (outputIndex > 0 && i == outputIndex+1){ // If token after output redirection,
            strcpy(outputFile, cmd.argv[i]);
            args[i] = NULL;
        }

        // if no I/O redirection yet, add to execvp args
        if (inputIndex == 0 && outputIndex == 0){
            args[i] = cmd.argv[i];
        }
    }

    args[cmd.argc] = NULL; // set last value of args to NULL

    // if command is cd, change directory
    if (strcmp(args[0], "cd") == 0){
        if (strcmp(args[1], "~") == 0){
            char* home = getenv("HOME");
            chdir(home);
        } else {
           int status = chdir(args[1]);
           if (status == -1){
                printf("%s: no such file or directory\n", args[1]);
           }
        }
    }

    // if command is history, print history
    else if (strcmp(args[0], "history") == 0){
        // create home-history filepath
        char* home = getenv("HOME");
        char* history = malloc(sizeof(home)+strlen("/techshell_history.txt")+1);
        strcpy(history, home);
        strcat(history, "/techshell_history.txt");

        // check if clearing history
        int clear = 0;
        for (int i=0; i<cmd.argc; i++){
            if (strcmp(args[i], "-c") == 0){
                clear = 1;
                break;
            }
        }

        // if NOT clearing history:
        if (clear != 1){
            // open history.txt
            FILE *filePtr;
            filePtr = fopen(history, "r");

            // print history file line by line
            char line[TOTAL_SIZE];
            while (fgets(line, TOTAL_SIZE, filePtr)){
                printf("%s", line);
            }
            fclose(filePtr); // close history file
        }

        // if clearing history:
        else {
            remove(history);
        }
    }

    //otherwise, run command normally
    else {
        int pid = fork(); // fork into child process

        if (pid == 0){ // child process:
            if (inputIndex > 0){
                // redirect input
                FILE* infile = fopen(inputFile, "r");
                dup2(fileno(infile), 0);
                fclose(infile);
            }
            if (outputIndex > 0){
                // redirect output
                FILE* outfile = fopen(outputFile, "w");
                dup2(fileno(outfile), 1);
                fclose(outfile);
            }

            // execute command in child process
            int status = execvp(args[0], args);
            if (status == -1){
                printf("%s: command not found\n", args[0]);
            } else {
               strerror(status); 
            }
        } else { // parent process:
            // wait for child process to finish before continuing
            wait(NULL);
        }
    }
}

void writeHistory(char* input){
    // create home-history filepath
    char* home = getenv("HOME");
    char* history = malloc(sizeof(home)+strlen("/techshell_history.txt")+1);
    strcpy(history, home);
    strcat(history, "/techshell_history.txt");

    // open/create history file and append input
    FILE *filePtr;
    filePtr = fopen(history, "ab");

    fprintf(filePtr, "%s\n", input);

    fclose(filePtr); // close history file
    free(history);
}