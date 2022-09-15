/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:10:14 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/15 19:11:01 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(int time_to_wait, long long execution_time)
{
	while (1)
	{
		if ((get_time() - execution_time) >= time_to_wait)
			break ;
	}
}

void routine(int i, t_arg args_to_info, long long time)
{
	while(1)
	{
		printf(" %lldms %d is take a fork\n",get_time() - time, i);
		printf(" %lldms %d is take a fork\n",get_time() - time, i);
		printf(" %lldms %d is eating\n",get_time() - time, i);
		ft_usleep(args_to_info.t_t_e, get_time());
		printf(" %lldms %d is sleeping\n",get_time() - time, i);
		ft_usleep(args_to_info.t_t_s, get_time());
		printf(" %lldms %d is thinking\n", get_time() - time,i);
	}
	exit(0);
}