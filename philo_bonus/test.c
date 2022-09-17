/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:06:20 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/16 17:56:55 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
#include <signal.h>
#include<pthread.h>

void *rot(void *arg)
{
    int *p;
    p = (int*)arg;
    *p += 1;
    return NULL;
}
int main()
{
    int pid;
    pthread_t th;
    int x = 0;
    int *a;
    a = &x;
    pid = fork();
    if(pid == 0)
    {
        pthread_create(&th, NULL, &rot, a);
        exit(0);
    }
    else{
        wait(NULL);
        printf("%d\n", *a);
    }
}