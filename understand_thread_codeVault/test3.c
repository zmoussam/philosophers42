/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:57:10 by zmoussam          #+#    #+#             */
/*   Updated: 2022/08/19 18:17:46 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<pthread.h>

long mails = 0;
pthread_mutex_t mutex;

void * routine()
{
    for (int i = 0; i < 10000000; i++){
        pthread_mutex_lock(&mutex);
        mails++;
        printf("mails = %ld\n",mails);
        pthread_mutex_unlock(&mutex);
        // read mails
        // increment
        // write mails
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    pthread_t p1, p2, p3, p4;
    pthread_mutex_init(&mutex, NULL);
    if(pthread_create(&p1, NULL, &routine, NULL) != 0)
    {
        return 1;
    }
    if(pthread_create(&p2, NULL, &routine, NULL) != 0)
    {
        return 2;
    }
    if(pthread_create(&p3, NULL, &routine, NULL) != 0)
    {
        return 3;
    }
    if(pthread_create(&p4, NULL, &routine, NULL) != 0)
    {
        return 4;
    }
    if(pthread_join(p1, NULL) != 0)
    {
        return 5;
    }
    if(pthread_join(p2, NULL) != 0)
    {
        return 6;
    }
    if(pthread_join(p3, NULL) != 0)
    {
        return 7;
    }
    if(pthread_join(p4, NULL) != 0)
    {
        return 8;
    }
    pthread_mutex_init(&mutex, NULL);
    printf("Number of mails: %ld\n", mails);
    return 0;
}