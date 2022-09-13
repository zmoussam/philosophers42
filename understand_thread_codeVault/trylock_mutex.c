/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trylock_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:41:30 by zmoussam          #+#    #+#             */
/*   Updated: 2022/08/21 20:08:10 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>

pthread_mutex_t stoveMutex;
int stoveFuel = 100;

void * routine(void *arg)
{
    pthread_mutex_lock(&stoveMutex);
    int fuelNeeded = (rand() % 20);
    if(stoveFuel - fuelNeeded < 0)
    {
        printf("No more fuel... going home\n");
    } else {
        stoveFuel -= fuelNeeded;
        printf("Fuel left %d\n", stoveFuel);
    }
    usleep(500000);
    pthread_mutex_lock(&stoveMutex);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    pthread_t th[10];
    for (int i = 0; i < 4; i++){
        pthread_mutex_init(&stoveMutex, NULL);
    }
    for (int i = 0; i < 10; i++){
        if (pthread_create(&th[i], NULL, &routine, NULL)) {
            perror("Failed to create thread");
        }
    }
    for (int i = 0; i < 10; i++){
        if (pthread_join(th[i], NULL)){
            perror("Failed to join thread");
        }
    }
    for (int i = 0; i < 4; i++){
        pthread_mutex_destroy(&stoveMutex[i]);
    }
    return 0;
}