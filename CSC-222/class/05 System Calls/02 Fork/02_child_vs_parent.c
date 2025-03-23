#include <stdio.h>
#include <unistd.h>

int main(){
    int pid = fork(); // pid is the process id

    // if pid is -1, then it failed to create the child
    if (pid < 0){
        printf("Failed to create child process\n");
        return 1;
    }

    // at this point, you are in both processes
    // pid has a different value depending on the process you're in
    // if pid is 0, then we're in the child process
    if (pid == 0){
        printf("Hello from the child process\n");
    } else {
        printf("Hello from the parent process\n");
    }

    printf("Hello from both\n");

    return 0;
}