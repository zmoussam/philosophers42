/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_barrier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:36:50 by zmoussam          #+#    #+#             */
/*   Updated: 2022/08/23 17:41:21 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Problem:
/* every thread rols a dice, saved its value in an array.

The main thread calculates the winner then
Each thread prints a message with whether or not they lost or won
*/ 

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

#define THREAD_NUM 8

int diceValues[8];
int status[8] = { 0 };

pthread_barrier_t barrierRolledDice;
pthread_barrier_t barrierCalculated;


void *rollDice(void *args){
    int index = *(int*)args;
    while(1){
        diceValues[index] = rand() % 6 + 1;
        pthread_barrier_wait(&barrierRolledDice);
        pthread_barrier_wait(&barrierCalculated);
        if(status[index] == 1){
            printf("(%d rolled %d) I won\n", index, diceValues[index]);
        } else {
            printf("(%d rolled %d) I lost\n", index, diceValues[index]);
        }
    }
    free(args);
    return(0);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    pthread_t th[THREAD_NUM];
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        int *a  = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], NULL, &rollDice, a)){
            perror("Failed to create thread");
        }
    }
    while(1){
        pthread_barrier_wait(&barrierRolledDice);
        // Calculate the winer 
        int max = 0;
        for(i = 0; i < THREAD_NUM; i++){
            if(diceValues[i] > max){
                max = diceValues[i];
            }
        }
        for(i = 0; i < THREAD_NUM; i++){
            if(diceValues[i] == max){
                status[i] = 1;
            } else {
                status[i] = 0;
            }
        }
        printf("===== NEW ROUND STARTED =====\n");
        sleep(1);
        pthread_barrier_wait(&barrierCalculated);
    }
    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(th[i], NULL)){
            perror("Failed to join thread");
        }
    }
    return 0;
}