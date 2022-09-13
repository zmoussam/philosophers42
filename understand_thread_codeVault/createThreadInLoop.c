/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createThreadInLoop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:32:25 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/13 16:11:05 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<pthread.h>

long mails = 0;
pthread_mutex_t mutex;

void * routine()
{
    for (int i = 0; i < 100000; i++){
        pthread_mutex_lock(&mutex);
        mails++;
       // printf("mails = %ld\n",mails);
        pthread_mutex_unlock(&mutex);
        // read mails
        // increment
        // write mails
        printf("%ldms  %d x is eating", time, id);
        printf("%ldms  %d x is eating", time, id);
        printf("%ldms  %d x is eating", time, id);
        printf("%ldms  %d x is eating", time, id);
        
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    pthread_t th[4];
    int i;
    pthread_mutex_init(&mutex, NULL);
    for(i = 0; i < 4; i++)
    {
        if(pthread_create(th + i, NULL, &routine, NULL) != 0){
            perror("Failed to create thread");
            return 1;
        }
        printf("Thread %d has started\n", i);
        // if(pthread_join(th[i], NULL) != 0)
        // {
        //     return 2;
        //}
     }
         for(i = 0; i < 4; i++){
            if(pthread_join(th[i], NULL) != 0)
            {
                return 2;
            }
            printf("Thread %d has finished execution \n", i);
         }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %ld\n", mails);
    return 0;
}
