/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:10:14 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/18 01:39:23 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_t_t_d(t_philos *philo)
{
	if ((get_time() - philo->time_of_last_meal) >= philo->arg_info.t_t_d)
	{
		printf("%lldms philo %d died 💀🎃\n",
			(get_time() - philo->time), philo->id);
		exit(0);
		sem_post(philo->fork);
	}
}
void	ft_usleep(int time_to_sleep, long long exec_time, t_philos *philo)
{
	while (1)
	{
		usleep(100);
		if (philo)
			check_t_t_d(philo);
		if (((get_time() - exec_time)) >= time_to_sleep)
			break ;
	}
}

void routine(t_philos *philosopher)
{
	if(philosopher->id % 2 == 0)
		ft_usleep(30, get_time(), NULL);
	while(1)
	{
		usleep(10);
		sem_wait(philosopher->fork);
		check_t_t_d(philosopher);
		printf("%lldms philo %d is take a fork 🍴\n", (get_time() - philosopher->time), philosopher->id);
		usleep(10);
		sem_wait(philosopher->fork);
		check_t_t_d(philosopher);
		printf("%lldms philo %d is take a fork 🍴\n", (get_time() - philosopher->time), philosopher->id);
		printf("%lldms philo %d is eating 🍽️ 🍔\n", (get_time() - philosopher->time), philosopher->id);
		philosopher->time_of_last_meal = get_time();
		ft_usleep(philosopher->arg_info.t_t_e, get_time(), NULL);
        if (philosopher->arg_info.check_last_arg == 1)
		{
            philosopher->arg_info.n_o_t_e_p_m_e--;
			if (philosopher->arg_info.n_o_t_e_p_m_e == 0)
                  break ;
		}
		printf("%lldms philo %d is sleeping 😴\n", get_time() - philosopher->time, philosopher->id);
		sem_post(philosopher->fork);
		sem_post(philosopher->fork);
		ft_usleep(philosopher->arg_info.t_t_s, get_time(), philosopher);
		check_t_t_d(philosopher);
	
		printf("%lldms philo %d is thinking 🤔 🤔\n", get_time() - philosopher->time,philosopher->id);
	}
	sem_close(philosopher->fork);
	exit(0);
}