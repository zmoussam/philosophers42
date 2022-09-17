/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:10:14 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/16 18:11:32 by zmoussam         ###   ########.fr       */
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
	}
}
void	ft_usleep(int time_to_wait, long long execution_time)
{
	while (1)
	{
		if ((get_time() - execution_time) >= time_to_wait)
			break ;
	}
}

void routine(t_philos *philosopher, sem_t *forks)
{
	while(1)
	{
		check_t_t_d(philosopher);
		sem_wait(forks);
		check_t_t_d(philosopher);
		printf(" %lldms philo %d is take a fork 🍴\n", (get_time() - philosopher->time), philosopher->id);
		printf(" %lldms philo %d is take a fork 🍴\n", (get_time() - philosopher->time), philosopher->id);
		printf(" %lldms philo %d is eating 🍽️ 🍔\n", (get_time() - philosopher->time), philosopher->id);
		philosopher->time_of_last_meal = get_time();
		ft_usleep(philosopher->arg_info.t_t_e, get_time());
		sem_post(forks);
        if (philosopher->arg_info.check_last_arg == 1)
		{
            philosopher->arg_info.n_o_t_e_p_m_e--;
			 if (philosopher->arg_info.n_o_t_e_p_m_e == 0)
                  break;
		}
		printf(" %lldms philo %d is sleeping 🥱 😴\n",get_time() - philosopher->time, philosopher->id);
		ft_usleep(philosopher->arg_info.t_t_s, get_time());
		check_t_t_d(philosopher);
		printf(" %lldms philo %d is thinking 🤔 🤔\n", get_time() - philosopher->time,philosopher->id);
	}
	sem_close(forks);
	exit(0);
}