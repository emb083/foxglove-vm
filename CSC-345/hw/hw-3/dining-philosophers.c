// Name: Elia Browning
// Date: 5/4/2025
// Assignment: Homework 3 - Dining Philosophers Problem

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define HUNGRY 0
#define THINKING 1
#define EATING 2
#define PERIOD 0.25

int numOfPhils; // number of phils, passed in as argument[1]
int numOfTimesToEat; // number of times to eat each, passed in as argument[2]
sem_t *forks;
int *state;
int *phils;
int *eaten;

// functions that may be helpful to create
void test(int); // used to check state of philsopher and state of each Fork
             // if philospher is hungry and both left and right are satisifed
             // then they should be able to eat now

void pickUpFork(int); // waits to grab forks for philospher (denotes when philospher is hungry)
void putDownFork(int); // puts forks back down (denotes when philospher is thinking)
void* philosopher(void *); // must be a pointer when working with threading
                     // determines first action of a philospher when thread is created

int main(int argc, char *argv[]) {
    numOfPhils = argv[1];
    numOfTimesToEat = argv[2];

    // thread usage
    pthread_t threads[numOfPhils];

    // memory allocation for forks, state, and philosphers
    forks = malloc(numOfPhils * sizeof(sem_t)); // tracks if fork is available
    state = malloc(numOfPhils * sizeof(int)); // tracks if phil can eat
    phils = malloc(numOfPhils * sizeof(int)); // track if phil is h, e, or t
    eaten = malloc(numOfPhils * sizeof(int)); // tracks how many times a phil has eaten

    // create philosphers and give them a state based on numOfPhils
    for (int i=0; i<numOfPhils; i++){
        // set state
        sem_init(&forks[i], 0, 1);
        state[i] = 0;
        phils[i] = rand()%2;
        eaten[i] = 0;
    }

    // create threads
    for (int i=0; i<numOfPhils; i++){
        pthread_create(&threads[i], NULL, philosopher, i);
    }

    for (int i=0; i<numOfPhils; i++){
        pthread_join(threads[i], NULL);
    }

    free(forks);
    free(state);
    free(phils);
    free(eaten);
    return 0;
}

void test(int phil){
    int forkL, forkR;
    sem_getvalue(&forks[phil], &forkL);
    sem_getvalue(&forks[(phil+1)%numOfPhils], &forkR);

    if (phils[phil]==HUNGRY && forkL==1 && forkR==1){ // if hungry and both forks are available
        state[phil] = 1; // get ready to eat

        if (state[(phil+1)%numOfPhils] == 1){ // if the phil to the right is also ready
            if (eaten[phil] < eaten[(phil+1)%numOfPhils]){ // and you've eaten less
                state[(phil+1)%numOfPhils] = 0; // you eat first
            } else { // but otherwise
                state[phil] = 0; // let them go first
            }
        }

    } else {
        state[phil] = 0;
    }
}

void pickUpFork(int phil){
    sem_wait(&forks[phil]);
    sem_wait(&forks[(phil+1)%numOfPhils]);
    printf("Philosopher %d is eating...\n", phil);
}

void putDownFork(int phil){
    sem_post(&forks[phil]);
    sem_post(&forks[(phil+1)%numOfPhils]);
    printf("Philosopher %d is thinking...\n", phil);
}

void *philosopher(void *phil){
    int i = (int)phil;

    switch (phils[i]) {
        case HUNGRY:
            printf("Philosopher %d is hungry...\n", i);
            break;
        case THINKING:
            printf("Philosopher %d is thinking...\n", i);
            break;
    }

    while (eaten[i] < numOfTimesToEat){ // until phil has eaten enough
        switch (phils[i]) {
            case HUNGRY:
                test(i); // check if can eat
                if (state[i] == 1){ // if so, start eating
                    pickUpFork(i);
                    phils[i] == EATING;
                }
                break;
            case EATING:
                eaten[i] += 1;
                sleep(PERIOD); // eat some
                putDownFork(i);
                phils[i] = THINKING;
                break;
            case THINKING:
                sleep(PERIOD); // think some
                phils[i] = HUNGRY;
                break;
        }
    }
}