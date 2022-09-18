/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_and_mutex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:45:10 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/18 19:52:31 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	if_there_is_one_philo(t_arg args, t_philos *philo)
{
	philo->arg_info = args;
	if (philo->arg_info.n_of_p == 1)
	{
		philo->time = get_time();
		if (pthread_create(&(philo->philo), NULL, &routine_for_one, philo))
		{
			pthread_mutex_lock(philo->msg);
			printf("philosopher %d was not created!!!\n", 1);
			ft_free(philo);
			exit(0);
		}
		ft_pthread_join(args.n_of_p, philo);
	}
}

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
			pthread_mutex_lock(philosophers->msg);
			printf("philosopher %d was not created!!!\n", i + 1);
			pthread_mutex_destroy(philosophers->msg);
			free(philosophers->msg);
			free(philosophers);
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

void	*init_left_forks_and_msg(t_philos *philos, int nbr_of_forks)
{
	int	i;

	i = 0;
	philos->msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philos->msg == NULL)
		return (write(1, "memory was not allocated!!\n", 27), exit(0), NULL);
	pthread_mutex_init(philos->msg, NULL);
	while (i < nbr_of_forks)
	{
		philos[i].left_fork = \
					(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!philos[i].left_fork)
			return (write(1, "memory was not allocated!!\n", 27), exit(0), NULL);
		philos[i].msg = philos[0].msg;
		pthread_mutex_init(philos[i].left_fork, NULL);
		i++;
	}
	return (NULL);
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
