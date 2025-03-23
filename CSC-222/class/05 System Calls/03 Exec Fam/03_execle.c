#include <unistd.h>

int main(){
    // execle
    // e is for environment variables
    // put environment variables in an array of strings
    // last value is NULL
    char *envVars[] = {"HPME=/home/usr", "PATH=/usr/bin:/bin", NULL};

    execle("/bin/ls", "ls", "-l", NULL, envVars);
}