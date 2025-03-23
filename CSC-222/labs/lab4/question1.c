#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Usage: ./question1 <executable>\n");
    } else {
        int pid = fork();
        if (pid == 0) {
            printf("Child %d:\n", getpid());
            char *execargs[] = {
                argv[1],
                NULL
            };
            execvp(execargs[0], execargs);
        }
    }
}