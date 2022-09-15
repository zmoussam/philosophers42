/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_to_sem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:41:08 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/13 23:04:04 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define THREAD_NUM 4
 sem_t semaphore;
void *routine(void *args)
{
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from thread %d\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
    return NULL;
}
int main(int argc, char *argv[])
{
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 1);
    int i;
    for(i = 0; i < THREAD_NUM; i++){
        int *a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&th[i], NULL, &routine, a) != 0){
            perror("Failed to create thread");
        }
    }

    
}