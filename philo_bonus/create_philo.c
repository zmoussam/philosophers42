/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:11:32 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/15 19:12:02 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philo(t_arg args_info)
{
	int i;
	int id;
	long long time;
	i = 0;

	while(i < args_info.n_of_p)
	{
		id = fork();
		if(id == 0)
		{
			time = get_time();
			routine(i + 1, args_info, time);
		}
		i++;	
	}
}