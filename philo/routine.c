/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:51:48 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/17 15:45:59 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(int time_to_wait, long long execution_time, t_philos *philo)
{
	while (1)
	{
		check_t_t_d(philo);
		if ((get_time() - execution_time) >= time_to_wait)
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
		exit(0);
		pthread_mutex_unlock(philo->msg);
	}
}

void	*routine(void *arg)
{
	t_philos	philo;

	philo = *(t_philos *)arg;
	if (philo.id % 2 == 0)
		ft_usleep(30, get_time(), &philo);
	while (1)
	{
		check_t_t_d(&philo);
		if (!take_left_fork(&philo))
			break ;
		take_right_fork(&philo);
		if (!is_eating(&philo))
			break ;
		is_sleeping(&philo);
		is_thinking(&philo);
	}
	return (NULL);
}
