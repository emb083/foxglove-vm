#include <unistd.h>

int main(){

    // execv
    // v is vector (i.e. an array)

    char *args[] ={
        "ls",
        "-al",
        "-h",
        NULL
    };

    execv("/bin/ls", args);

    return 0;

}