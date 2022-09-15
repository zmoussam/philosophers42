/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calling_fork_mult_time.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:12:28 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/15 15:25:59 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

int main(int argc, char **argv)
{
    int id1 = fork();
    int id2 = fork();
    if(id1 == 0){
        if(id2 == 0){
            printf("We are process y\n");
        } else {
            printf("We are process x\n");
        }
    }
    else {
        if(id2 == 0){
            printf("We are process z\n");
        }
    }
    while(wait(NULL) != -1 || errno != ECHILD);
    return 0;
}