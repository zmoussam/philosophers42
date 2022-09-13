/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:48:25 by zmoussam          #+#    #+#             */
/*   Updated: 2022/08/21 17:46:27 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

/* basically this order of execution ocurred:
car1: lock -> cond_wait -> unlock
car2: lock -> cond_wait -> unlock
fueler1: lock
car3: lock (waiting on lock)
car4: lock (waiting on lock)
*/
void *fuel_filling(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15; 
        printf("Filled fuel.. %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
    }
}

void *car(void *arg)
{
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40)
    {
        printf("No fuel. Waiting... \n");
        pthread_cond_wait(&condFuel, &mutexFuel);
        // Equivalent to:
        // pthread_mutex_unlock(&mutexFuel);
        // wait for signal on condFuel
        // pthread_mutex_lock(&mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    
}

int main(int argc, char **argv)
{
    pthread_t th[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    for (int i = 0; i < 2; i++){
        if (i == 1){
            if(pthread_create(&th[i], NULL, &fuel_filling, NULL)){
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &car, NULL)){
                perror("Failed to create thread");
            }
        }
    }
    for (int i = 0; i < 2; i++){
        if (pthread_join(th[i], NULL)) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return (0);
}