/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:06:20 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/15 17:26:59 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

int main()
{
   int i = 0;
   while(i < 5)
   {
       int id = fork();
       if(id == 0)
       {
           printf("salut %d my parent is %d\n", getpid(), getppid());
           exit(0);
       }
       i++;
   }
   while(wait(NULL) != -1);
}