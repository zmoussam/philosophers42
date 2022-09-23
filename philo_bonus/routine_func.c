/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:49:35 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 12:45:10 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_first_fork(t_philos *philosopher)
{
	sem_wait(philosopher->fork);
	check_t_t_d(philosopher);
	sem_wait(philosopher->print_msg);
	printf("%lldms philo %d is take a fork 🍴\n", \
		(get_time() - philosopher->time), philosopher->id);
	sem_post(philosopher->print_msg);
}

void	take_second_fork(t_philos *philosopher)
{
	sem_wait(philosopher->fork);
	check_t_t_d(philosopher);
	sem_wait(philosopher->print_msg);
	printf("%lldms philo %d is take a fork 🍴\n", \
		(get_time() - philosopher->time), philosopher->id);
}

int	is_eating(t_philos *philosopher)
{
	printf("%lldms philo %d is eating 🍽️ 🍔\n", \
		(get_time() - philosopher->time), philosopher->id);
	sem_post(philosopher->print_msg);
	philosopher->time_of_last_meal = get_time();
	ft_usleep(philosopher->arg_info.t_t_e, get_time(), NULL);
	sem_post(philosopher->fork);
	sem_post(philosopher->fork);
	if (philosopher->arg_info.n_o_t_e_p_m_e != 0)
	{
		philosopher->arg_info.n_o_t_e_p_m_e--;
		if (philosopher->arg_info.n_o_t_e_p_m_e == 0)
			return (0);
	}
	return (1);
}

void	is_sleeping(t_philos *philosopher)
{
	sem_wait(philosopher->print_msg);
	printf("%lldms philo %d is sleeping 😴\n", \
		(get_time() - philosopher->time), philosopher->id);
	sem_post(philosopher->print_msg);
	ft_usleep(philosopher->arg_info.t_t_s, get_time(), philosopher);
	check_t_t_d(philosopher);
}

void	is_thinking(t_philos *philosopher)
{
	sem_wait(philosopher->print_msg);
	printf("%lldms philo %d is thinking 🤔 🤔\n", \
		(get_time() - philosopher->time), philosopher->id);
	sem_post(philosopher->print_msg);
}
