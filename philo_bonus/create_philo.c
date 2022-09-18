/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:11:32 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/18 01:39:32 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philo(t_arg args_info, t_philos *philosopher)
{
	int i;
	long long time;
	int *tab;
	tab = (int *)malloc(sizeof(int) * args_info.n_of_p);
	i = 0;
	while (i < args_info.n_of_p)
	{
		philosopher[i].fork_id = fork();
		if (philosopher[i].fork_id == 0)
		{
			philosopher[i].id = i + 1;
            philosopher[i].arg_info = args_info;
			philosopher[i].time = get_time();
			philosopher[i].time_of_last_meal = get_time();
			philosopher[i].fork = philosopher->fork;
			philosopher[i].print_msg = philosopher->print_msg;
			routine(&philosopher[i]);
		}
		else {
			tab[i] = philosopher[i].fork_id;
		}
		i++;	
	}
	while(1)
	{
		if (waitpid(-1, NULL, WNOHANG))
		{
			i = 0;
			while(i < args_info.n_of_p)
			{
				kill(philosopher[i].fork_id, SIGKILL);
				i++;
			}
			sem_unlink("/forks");
			sem_close(philosopher->fork);
			exit(0);
		}
	}
	sem_unlink("/forks");
	sem_close(philosopher->fork);
}