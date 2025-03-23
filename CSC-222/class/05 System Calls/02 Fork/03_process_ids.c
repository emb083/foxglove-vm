#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int pid = fork();

    if (pid == -1){
        printf("Failed to create child process");
        return 1;
    }

    if (pid == 0){
        // this is only happening in the child process
        printf("pid in child: %d\n", pid);
        printf("From child; id of child is %d\n", getpid()); // the actual process id
        printf("From child; id of parent is: %d\n", getppid()); // might return 1 (if parent is done)
    } else {
        // this is only happening in the parent process
        printf("From parent; id of child is %d\n", pid);
        printf("From parent; id of parent is %d\n", getpid());
        wait(NULL);
    }

}