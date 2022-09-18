/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:06:48 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/17 23:41:04 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* For Semaphore */
#include<semaphore.h>
#include<fcntl.h> //For O_* constants
#include<sys/stat.h> // For mode constants

#include<stdlib.h>
#include<stdio.h>

/* For Fork */
#include<sys/types.h>
#include<unistd.h>

/* For Killing the child process */
#include<sys/wait.h>

#define SEM_NAME_1 "/SEM_1"
#define SEM_NAME_2 "/SEM_2"

int main()
{
    sem_t *sem1 = NULL;
    sem_t *sem2 = NULL;
    int id;
    int i = 1;
    int id2;

    sem1 = sem_open(SEM_NAME_1, O_CREAT | O_EXCL, 0777, 1);
    sem2 = sem_open(SEM_NAME_2, O_CREAT | O_EXCL ,0777,  0);
    id = fork();
    if(id == 0){
        printf("%d \n", getpid());
       while(1){
           sleep(1);
           printf("hi\n");
       }
    }
    id2 = fork();
    if(id2 == 0){
        printf("%d \n", getpid());
        exit(0);
    }
        sleep(1);
        while(1)
         if(waitpid(-1, NULL, WNOHANG))
         {
             printf("killed\n");
             printf("%d\n", id2);
             kill(id, SIGKILL);
             exit(0) ;
             
         }
}