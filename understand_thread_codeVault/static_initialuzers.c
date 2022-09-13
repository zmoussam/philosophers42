/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_initialuzers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:27:43 by zmoussam          #+#    #+#             */
/*   Updated: 2022/08/30 20:49:28 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

#define THREAD_NUM 2

// you dont need to use pthread_mutex_init() and pthread_mutex_destroy();
pthread_mutex_t mutexFuel = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condFuel = PTHREAD_COND_INITIALIZER;

void *routine(void *arg)
{
}
int main(int argc , char **argv)
{
    
}    