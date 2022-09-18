/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:51:48 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/18 20:00:27 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(int time_to_sleep, long long exec_time, t_philos *philo)
{
	while (1)
	{
		usleep(50);
		if (philo)
			check_t_t_d(philo);
		if (((get_time() - exec_time)) >= time_to_sleep)
			break ;
	}
}

void	check_t_t_d(t_philos *philo)
{
	if ((get_time() - philo->time_of_last_meal) >= philo->arg_info.t_t_d)
	{
		pthread_mutex_lock(philo->msg);
		printf("%lldms philo %d died 💀🎃\n",
			(get_time() - philo->time), philo->id);
		pthread_mutex_destroy(philo->msg);
		exit(0);
	}
}

void	*routine_for_one(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d has taken a fork 🍴\n",
		(get_time() - philo->time), philo->id);
	ft_usleep(philo->arg_info.t_t_d, get_time(), NULL);
	printf("%lldms philo %d died 💀🎃\n",
		(get_time() - philo->time), philo->id);
	ft_free(philo);
	exit(0);
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(30, get_time(), NULL);
	while (1)
	{
		check_t_t_d(philo);
		take_left_fork(philo);
		take_right_fork(philo);
		if (!is_eating(philo))
			break ;
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}
