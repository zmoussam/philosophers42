/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:10:14 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 00:51:36 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_t_t_d(t_philos *philo)
{
	if ((get_time() - philo->time_of_last_meal) >= philo->arg_info.t_t_d)
	{
		sem_wait(philo->print_msg);
		printf("%lldms philo %d died 💀🎃\n",
			(get_time() - philo->time), philo->id);
		exit(EXIT_SUCCESS);
	}
}

void	ft_usleep(int time_to_sleep, long long exec_time, t_philos *philo)
{
	while (1)
	{
		if (((get_time() - exec_time)) >= time_to_sleep)
			break ;
		if (philo)
			check_t_t_d(philo);
		usleep(50);
	}
}

void	routine(t_philos *philosopher)
{
	if (philosopher->id % 2 == 0)
		ft_usleep(30, get_time(), NULL);
	while (1)
	{
		take_first_fork(philosopher);
		take_second_fork(philosopher);
		if (!is_eating(philosopher))
			break ;
		is_sleeping(philosopher);
		is_thinking(philosopher);
	}
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT_MSG);
	sem_close(philosopher->fork);
	sem_close(philosopher->print_msg);
	exit(EXIT_SUCCESS);
}
