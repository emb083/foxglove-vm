// Name: Elia Browning
// Date: 5/5/2025
// Assignment: Homework 3 - Dining Philosophers Problem TAKE 2

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define PERIOD 0.25

int numOfPhils;
int numOfTimesToEat;
sem_t *forks;
int *state;
int *phils;

// functions that may be helpful to create
void test(); // used to check state of philsopher and state of each Fork
             // if philospher is hungry and both left and right are satisifed
             // then they should be able to eat now

void pickUpFork(); // waits to grab forks for philospher (denotes when philospher is hungry)
void putDownFork(); // puts forks back down (denotes when philospher is thinking)
void* philosopher(void *); // must be a pointer when working with threading
                           // determines first action of a philospher when thread is created

int main(int argc, char *argv[]) {
    numOfPhils = atoi(argv[1]);
    numOfTimesToEat = atoi(argv[2]);

    // thread usage
    pthread_t threads[numOfPhils];

    // memory allocation for forks, state, and philosphers
    forks = malloc(numOfPhils * sizeof(sem_t)); // tracks if fork is available
    state = malloc(numOfPhils * sizeof(int)); // tracks if phil is t or h, and how long they've been waiting
    phils = malloc(numOfPhils * sizeof(int)); // tracks how many times a philosopher has eaten

    srand(time(NULL)); // make random function actually random

    // set state
    for (int i=0; i<numOfPhils; i++){
        sem_init(&forks[i], 0, 1);
        state[i] = rand()%2;
        phils[i] = 0;

        switch (state[i]) {
            case 0:
                printf("Philosopher %d is thinking...\n", i);
                break;
            case 1:
                printf("Philosopher %d is hungry...\n", i);
                break;
        }
    }

    // create threads based on numOfPhils
    while (1) {
        for (int i=0; i<numOfPhils; i++){
            pthread_create(&threads[i], NULL, philosopher, (void *)(intptr_t)i);
        }
        for (int i=0; i<numOfPhils; i++){
            pthread_join(threads[i], NULL);
        }

        int break_flag = 1;
        for (int i=0; i<numOfPhils; i++){
            if (phils[i] < numOfTimesToEat){
                break_flag = 0;
                break;
            }
        }
        if (break_flag == 1){
            break;
        }
    }
    

    free(forks);
    free(state);
    free(phils);
    return 0;
}

void test(){
    int forkL, forkR, philNext;

    // case 1: hungry


    //      case 1a: fork not available
    //          stay hungry, wait
    //      case 1b: fork available, neighbor DOESN'T want it
    //          pick up fork, eat
    //      case 1c: fork available, neighbor wants it    
    //          choose who eats and who waits based on who has eaten less
    //          if eaten same amount, long wait goes first
    // case 2: thinking
    //      put down forks, become hungry
}

void pickUpFork(){

}

void putDownFork(){

}

void * philosopher(void *arg){
    
}