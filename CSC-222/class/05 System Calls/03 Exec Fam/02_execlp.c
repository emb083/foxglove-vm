#include <unistd.h>

int main(){
    // execlp
    // p is for PATH
    execlp("ls", "ls", "-alh", NULL);
}