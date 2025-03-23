#include <stdio.h>

int main(int argc, char *argv[]){
    // the header above is a standard signature for taking in command line arguments

    // argc represents the number of arguments coming in
    //     - stands for argument count

    // argv is a pointer to where the arguments are stored in memory
    //     - stands for argument vector
    //     - *argv[] represents a pointer to the lcoation of an array of strings
    //         - strings are character arrays

    // argv[0] stores the name or path of the program being executed
    // argv[1] through argv[argc-1] stores any input that followed the filename on execution
    // argv[argc] sounds like an out-of-bounds error, but it's not! stores null

    printf("argc: %d\n", argc);

    for (int i=0; i < argc; i++){
        printf("argv[%d] : %s\n", i, argv[i]);
    }

    printf("argv[%d] : %s\n", argc, argv[argc]);

    return 0;
}