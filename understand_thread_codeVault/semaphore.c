/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:06:48 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/16 17:59:22 by zmoussam         ###   ########.fr       */
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

    sem1 = sem_open(SEM_NAME_1, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
    sem2 = sem_open(SEM_NAME_2, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
    if(fork() == 0){
        printf("1\n");
        sem_post(sem1);
        sem_wait(sem2);
        printf("3\n");
        sem_post(sem1);

        /* evry process closes the sems */
        sem_close(sem1);
        sem_close(sem2);
    } else {
        sem_wait(sem1);
        printf("2\n");
        sem_post(sem2);
        sem_wait(sem1);
        printf("4\n");
        
        wait(NULL);

        sem_close(sem1);
        sem_close(sem2);
        sem_unlink(SEM_NAME_1);
        sem_unlink(SEM_NAME_2);
    }
}