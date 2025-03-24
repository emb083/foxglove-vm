// Name: Elia Browning
// Date: 3/23/2025
// Description: Homework 1 - Signal Handler

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include "signalTools.h" 

int usr1block = 1;

// function prototypes
void handle_SIGINT(int signal);
void handle_SIGTERM(int signal);
void handle_SIGUSR1(int signal);
void handle_SIGUSR2(int signal);


int main() {
    printf("Program started. PID: %d\n", getpid());

    setUpSignal(SIGINT, handle_SIGINT);
    setUpSignal(SIGTERM, handle_SIGTERM);
    setUpSignal(SIGUSR1, handle_SIGUSR1);
    setUpSignal(SIGUSR2, handle_SIGUSR2);

    printf("Waiting for signals...\n");
    for (;;){
        pause();
    }
}

void handle_SIGINT(int signal){
    printSignalInfo(signal);
    if (usr1block == 0){
        // signal is unblocked
        blockSignal(SIGUSR1, 1);
        usr1block = 1;
        printf("SIGINT received: Blocking SIGUSR1.\n");
    } else if (usr1block == 1){
        // signal is blocked
        unblockSignal(SIGUSR1, 1);
        usr1block = 0;
        printf("SIGINT received: Unblocking SIGUSR1.\n");
    }
}

void handle_SIGTERM(int signal){
    printSignalInfo(signal);
    printf("SIGERM received: Exiting the program.\n");
    exit(0);
}

void handle_SIGUSR1(int signal){
    printSignalInfo(signal);

    time_t t;
    time(&t);

    FILE *filePtr;
    filePtr = fopen("status.txt", "wb");

    printf("### STATUS REPORT ###\n");
    printf("Current Time: %s\n", ctime(&t));
    printf("Uptime: %ld seconds\n", time(NULL));
    printf("### END OF REPORT ###\n");

    fprintf(filePtr, "### STATUS REPORT ###\n");
    fprintf(filePtr, "Current Time: %s\n", ctime(&t));
    fprintf(filePtr, "Uptime: %ld seconds\n", time(NULL));
    fprintf(filePtr, "### END OF REPORT ###\n");

    fclose(filePtr);
}

void handle_SIGUSR2(int signal){
    printSignalInfo(signal);
    runTestCases();
}