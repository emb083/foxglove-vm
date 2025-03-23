#include <unistd.h>

int main(){
    // execv combined with execlp
    // execvp checks the path variable for the executable

    char *args[] = {
        "cp",
        "03_execle",
        "garb.c",
        NULL
    };

    execvp(args[0], args);

    return 0;
}