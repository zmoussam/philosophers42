/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createThreadInLoop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:32:25 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/17 16:42:34 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex;

void * routine(void *arg)
{
    long *p;
    p = (long*)arg;
    for (int i = 0; i < 2; i++){
        pthread_mutex_lock(&mutex);
        *p += 1;
        printf("th = %ld\n", *p);
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

int main(int argc, char **argv)
{

    pthread_t th[4];
    long *mails;
    int i;
    long j;
    j = 1;
    mails = &j;
    pthread_mutex_init(&mutex, NULL);
    for(i = 0; i < 4; i++)
    {
        if(pthread_create(th + i, NULL, &routine, mails) != 0){
            perror("Failed to create thread");
            return 1;
        }
     }
         for(i = 0; i < 4; i++){
            if(pthread_join(th[i], NULL) != 0)
            {
                return 2;
            }
            // printf("Thread %d has finished execution \n", i);
         }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %ld\n", j);
    return 0;
}
