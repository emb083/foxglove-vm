#include <unistd.h>

int main(){
    // execl is for execute list (of arguments)
    // 0th arg is filepath to command
    // following args are the arguments passed to the command:
    // - 1st arg is the command itself
    // - nth arg is NULL

    // example with ls
    execl("/bin/ls", "ls", "-al", "-h", NULL);
}