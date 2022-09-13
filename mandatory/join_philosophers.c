/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:48:21 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/03 22:40:32 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_pthread_join(int nbr_of_philosophers, t_philos *philos)
{
    int i;
    i = 0;
    while(i < nbr_of_philosophers)
    {
        if(pthread_join(philos[i].philo, NULL))
            printf("thread %d was not joined the main thread\n", i);
        i++;
    }
}