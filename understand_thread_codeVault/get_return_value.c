/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_return_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:23:39 by zmoussam          #+#    #+#             */
/*   Updated: 2022/08/19 19:31:02 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
void * roll_dice()
{
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    return (void *) result; 
}
int main(int argc, char **argv)
{
    int *res;
    //srand(time(NULL));
    pthread_t th;
    if(pthread_create(&th, NULL, &roll_dice, NULL)  != 0){
        return 1;
    }
    if(pthread_join(th, (void **) &res) != 0){
        return 2;
    }
    printf("main res: %p\n", res);
    printf("result: %d\n", *res);
    free(res);
    return 0;
}