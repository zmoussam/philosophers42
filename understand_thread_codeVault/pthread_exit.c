/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:11:21 by zmoussam          #+#    #+#             */
/*   Updated: 2022/08/21 20:24:18 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

void * roll_dice()
{
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    sleep(2);
    printf("Thread result: %d\n", value);
    pthread_exit((void*) result);
}
int main(int argc, char **argv)
{
    int *res;
    srand(time(NULL));
    pthread_t th;
    if(pthread_create(&th, NULL, &roll_dice, NULL)){
        return 1;
    }
    // pthread_exit(0);
    if (pthread_join(th, (void**)  &res)){
        return 2;
    }
    printf("Result: %d\n", *res);
    free(res);
    return (0);
}