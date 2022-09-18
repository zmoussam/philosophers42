/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_and_mutex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:45:10 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/18 00:50:02 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philosophers(t_arg philo_info, t_philos *philosophers)
{
	int	i;

	i = 0;
	while (i < philo_info.n_of_p)
	{
		philosophers[i].arg_info = philo_info;
		philosophers[i].time = get_time();
		philosophers[i].time_of_last_meal = philosophers[i].time;
		if (pthread_create(&((philosophers[i]).philo), NULL, \
				&routine, &philosophers[i]))
		{
			printf("philosopher %d was not created!!!\n", i + 1);
			exit(0);
		}
		i++;
	}
	return (0);
}

void	init_id(t_philos *philo_info, int nbr_of_philo)
{
	int	i;

	i = 0;
	while (i < nbr_of_philo)
	{
		philo_info[i].id = i + 1;
		i++;
	}
}

void	init_left_forks_and_msg(t_philos *philos, int nbr_of_forks)
{
	int	i;
	
	i = 0;
	philos->msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if(philos->msg == NULL)
		//exit(0);
	pthread_mutex_init(philos->msg, NULL);
	while (i < nbr_of_forks)
	{
		philos[i].left_fork = \
					(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		philos[i].msg = philos[0].msg;
		pthread_mutex_init(philos[i].left_fork, NULL);
		i++;
	}
}

void	init_right_forks(t_philos *philos, int nbr_of_philo)
{
	int	i;

	i = 0;
	while (i < nbr_of_philo)
	{
		if (i == 0)
			philos[i].right_fork = philos[nbr_of_philo - 1].left_fork;
		else
			philos[i].right_fork = philos[i - 1].left_fork;
		i++;
	}
}
