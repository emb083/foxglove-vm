// Name: Elia Browning
// Date: 5/4/2025
// Assignment: Homework 3 - Dining Philosophers Problem

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define HUNGRY 0
#define THINKING 1
#define EATING 2
#define PERIOD 250000

int numOfPhils;
int numOfTimesToEat;
sem_t *forks;
int *state;
int *phils;
int *eaten;
int threadCount = 0; // ensures threads will wait until are threads are created to start their functions

void test(int); // used to check state of philsopher and state of each Fork
             // if philospher is hungry and both left and right are satisifed
             // set state tracker as ready to eat

void pickUpFork(int);
void putDownFork(int);
void* philosopher(void *); // function each thread runs

int main(int argc, char *argv[]) {
    numOfPhils = atoi(argv[1]);
    numOfTimesToEat = atoi(argv[2]);

    pthread_t threads[numOfPhils]; // tracks thread ids

    // memory allocation for forks, state, and philosphers
    forks = malloc(numOfPhils * sizeof(sem_t)); // tracks if fork is available
    state = malloc(numOfPhils * sizeof(int)); // tracks if phil can eat
    phils = malloc(numOfPhils * sizeof(int)); // track if phil is h, e, or t
    eaten = malloc(numOfPhils * sizeof(int)); // tracks how many times a phil has eaten

    srand(time(NULL)); // make rand function actually random

    // set state
    for (int i=0; i<numOfPhils; i++){
        sem_init(&forks[i], 0, 1);
        state[i] = 0;
        phils[i] = rand()%2;
        eaten[i] = 0;

        switch (phils[i]) {
            case HUNGRY:
                printf("Philosopher %d is hungry...\n", i);
                break;
            case THINKING:
                printf("Philosopher %d is thinking...\n", i);
                break;
        }
    }

    // create threads
    for (int i=0; i<numOfPhils; i++){
        pthread_create(&threads[i], NULL, philosopher, (void *)(intptr_t)i);
        threadCount++;
    }

    // wait for all threads to finish
    for (int i=0; i<numOfPhils; i++){
        pthread_join(threads[i], NULL);
    }

    // free allocated memory
    free(forks);
    free(state);
    free(phils);
    free(eaten);
    return 0;
}

void test(int phil){
    int forkL, forkR, philL, philR;
    if (phil == 0){
        philL = numOfPhils-1;
    } else {
        philL = phil-1;
    }
    philR = (phil+1)%numOfPhils;
    sem_getvalue(&forks[phil], &forkL);
    sem_getvalue(&forks[philR], &forkR);

    // If only two phils (edgecase):
    if (numOfPhils == 2){
        // If thinking or eating:
        if (phils[phil] == THINKING || phils[phil] == EATING){
            state[phil] = 0; // not readying to eat
        }
        // If hungry:
        else {
            // Case 1: Both forks are available
            if (forkL == 1 && forkR == 1){
                //  Case 1a: Neighbor not ready to eat
                if (state[philR] != 1){
                    state[phil] = 1; // get ready to eat
                }
                //  Case 1b: Neighbor ready to eat
                else {
                    // Case 1b1: Least eaten
                    if (eaten[phil] < eaten[philR]){
                        state[phil] = 1; // eat first
                    }
                    // Case 1b2: Match eaten
                    else if (eaten[phil] == eaten[philR]){
                        state[phil] = phil; // let higher index go first
                        // yes i know this is inconsistent with how
                        // the algorithm normally works, which
                        // chooses the lowest index
                        // but this is one line of code with no if-statements, so -_-
                    }
                    // Case 1b3: Not least
                    else {
                        state[phil] = 0; // let them eat first
                    }
                }
            }
            // Case 2: Both forks are not available
            else {
                state[phil] = 0;
            }
        }
        
    } else { // NORMAL ALGORITHM
        // If thinking or eating:
        if (phils[phil] == THINKING || phils[phil] == EATING){
            state[phil] = 0; // not readying to eat
        // If hungry:
        } else {
            // Case 1: Both forks are available
            if (forkL == 1 && forkR == 1){
                // Case 1a: Neither neighbor is ready to eat
                if (state[philL] != 1 && state[philR] != 1){
                    state[phil] = 1; // get ready to eat
                // Case 1b: A neighbor IS ready to eat
                } else {
                    // Case 1b1: Least eaten
                    if (eaten[phil] < eaten[philL] && eaten[phil] < eaten[philR]){
                        state[phil] = 1; // get ready to eat
                    // Case 1b2: Matched for least eaten
                    } else if (eaten[phil] == eaten[philL] || eaten[phil] == eaten[philR]) {
                        // Case 1b2a: Lowest index
                        if (phil < philL) {
                            state[phil] = 1; // eat first
                        } else {
                            // Case 1b2b: Matched with lower index
                            if (eaten[phil] == eaten[philL]){
                                state[phil] = 0; // let them eat first
                            // Case 1b2c: Matched with higher index
                            } else if (eaten[phil] == eaten[philR]) {
                                state[phil] = 1; // go first
                            }
                        }
                    // Case 1b2: Not eaten the least
                    } else {
                        state[phil] = 0;
                    }
                }
            // Case 2: Both forks are not available
            } else {
                state[phil] = 0;
            }
        }
    }

    
}

void pickUpFork(int phil){
    printf("Philosopher %d is eating...\n", phil);
    sem_wait(&forks[phil]); // pick up left fork
    sem_wait(&forks[(phil+1)%numOfPhils]); // pick up right fork
}

void putDownFork(int phil){
    printf("Philosopher %d is thinking...\n", phil);
    sem_post(&forks[phil]); // put down left fork
    sem_post(&forks[(phil+1)%numOfPhils]); // put down right fork
}

void *philosopher(void *phil){
    // wait until all threads are created to continue
    while (threadCount < numOfPhils){
        usleep(100000);
    }

    int i = (intptr_t)phil;

    while (eaten[i] < numOfTimesToEat){ // until phil has eaten enough
        switch (phils[i]) {
            case HUNGRY:
                test(i); // check if can eat
                if (state[i] == 1){ // if so, start eating
                    pickUpFork(i);
                    phils[i] == EATING;

                    usleep(PERIOD); // eat some
                    putDownFork(i); // start thinking
                    phils[i] = THINKING;
                    eaten[i] += 1;

                }
                break;
            case THINKING:
                if (eaten[i] < numOfTimesToEat){ // if philosopher has met eating limit, don't become hungry again
                    usleep(PERIOD); // think some
                    printf("Philosopher %d is hungry...\n", i);
                    phils[i] = HUNGRY; // become hungry again
                    break;
                }
        }
    }
    pthread_exit(NULL); // exit thread
}