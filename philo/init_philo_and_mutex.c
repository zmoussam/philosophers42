/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_and_mutex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:45:10 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 01:21:22 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	if_there_is_one_philo(t_philos *philo)
{
	if (philo->arg_info.n_of_p == 1)
	{
		philo->time = get_time();
		if (pthread_create(&(philo->philo), NULL, &routine_for_one, philo))
		{
			pthread_mutex_lock(philo->msg);
			printf("philosopher %d was not created!!!\n", 1);
			return (0);
		}
		return (0);
	}
	return (1);
}

int	start_philosophers(t_philos *philosophers)
{
	int	i;

	i = 0;
	if (!if_there_is_one_philo(philosophers))
		return (0);
	while (i < philosophers->arg_info.n_of_p)
	{
		philosophers[i].time = get_time();
		philosophers[i].time_of_last_meal = philosophers[i].time;
		if (pthread_create(&((philosophers[i]).philo), NULL, &routine, \
			&philosophers[i]) || pthread_detach(philosophers[i].philo))
		{
			pthread_mutex_lock(philosophers->msg);
			printf("philosopher %d was not created!!!\n", i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philo(t_philos *philos, t_arg philo_info)
{
	int	i;

	i = 0;
	philos->check_die = (int *)malloc(sizeof(int));
	philos->count_meal = (int *)malloc(sizeof(int));
	if (philos->check_die == NULL || philos->count_meal == NULL)
		return (write(1, "memory was not allocated!!\n", 27));
	philos->check_die[0] = 1;
	philos->count_meal[0] = 0;
	while (i < philo_info.n_of_p)
	{
		philos[i].arg_info = philo_info;
		philos[i].id = i + 1;
		philos[i].check_die = philos[0].check_die;
		philos[i].count_meal = philos[0].count_meal;
		i++;
	}
	if (init_forks(philos) || init_mutex(philos))
		return (1);
	return (0);
}

int	init_forks(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->arg_info.n_of_p)
	{
		philo[i].left_fork = \
					(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (philo[i].left_fork == NULL)
			return (write(1, "memory was not allocated!!\n", 27));
		pthread_mutex_init(philo[i].left_fork, NULL);
		i++;
	}
	i = 0;
	while (i < philo->arg_info.n_of_p)
	{
		if (i == 0)
			philo[i].right_fork = philo[philo->arg_info.n_of_p - 1].left_fork;
		else
			philo[i].right_fork = philo[i - 1].left_fork;
		i++;
	}
	return (0);
}

int	init_mutex(t_philos *philos)
{
	int	i;

	i = 0;
	philos->msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philos->die = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philos->meals = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (philos->msg == NULL || philos->die == NULL || philos->meals == NULL)
		return (write(1, "memory was not allocated!!\n", 27));
	pthread_mutex_init(philos->msg, NULL);
	pthread_mutex_init(philos->die, NULL);
	pthread_mutex_init(philos->meals, NULL);
	while (i < philos->arg_info.n_of_p)
	{
		philos[i].msg = philos->msg;
		philos[i].die = philos->die;
		philos[i].meals = philos->meals;
		i++;
	}
	return (0);
}
