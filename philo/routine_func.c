/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:33:21 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/21 22:04:52 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_left_fork(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	check_t_t_d(philo);
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d has taken a fork 🍴\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
}

void	take_right_fork(t_philos *philo)
{
	pthread_mutex_lock(philo->right_fork);
	check_t_t_d(philo);
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d has taken a fork 🍴\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
}

int	is_eating(t_philos *philo)
{
	philo->time_of_last_meal = get_time();
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d is eating 🍽️ 🍔\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
	ft_usleep(philo->arg_info.t_t_e, get_time(), NULL);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->arg_info.n_o_t_e_p_m_e != 0)
	{
		philo->arg_info.n_o_t_e_p_m_e--;
		if (philo->arg_info.n_o_t_e_p_m_e == 0)
			return (0);
	}
	return (1);
}

void	is_sleeping(t_philos *philo)
{
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d is sleeping 😴\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
	ft_usleep(philo->arg_info.t_t_s, get_time(), philo);
}

void	is_thinking(t_philos *philo)
{
	pthread_mutex_lock(philo->msg);
	printf("%lldms philo %d is thinking 🤔\n",
		(get_time() - philo->time), philo->id);
	pthread_mutex_unlock(philo->msg);
}
