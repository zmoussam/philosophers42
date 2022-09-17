/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:11:32 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/16 17:51:45 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philo(t_arg args_info, t_philos *philosopher, sem_t *forks)
{
	int i;
	long long time;
	i = 0;
	forks = sem_open(SEM_NAME_1, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, (int)(args_info.n_of_p / 2));
	while (i < args_info.n_of_p)
	{
		philosopher[i].fork_id = fork();
		if (philosopher[i].fork_id == 0)
		{
			philosopher[i].time = get_time();
			philosopher[i].time_of_last_meal = get_time();
			philosopher[i].id = i + 1;
            philosopher[i].arg_info = args_info;
			routine(&philosopher[i], forks);
			sem_close(forks);
		}
		else {
	
		}
		i++;	
	}
	while(waitpid(-1, NULL, WNOHANG) != -1 || errno != ECHILD);
}