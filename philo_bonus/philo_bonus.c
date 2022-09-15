/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:02:01 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/15 19:12:13 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"


int main(int argc, char **argv)
{
    t_arg		args_to_info;
    t_philos	*philo_infos;
	sem_t		*take_fork;
	int i;
	int id;
	long long time;
	i = 0;
    if (argc == 5 || argc == 6)
	{
		parssing(argv);
		get_arg_to_int(argv, &args_to_info);
		sem_init(take_fork, 0, (args_to_info.n_of_p / 2));
		create_philo(args_to_info);
		while(wait(NULL) != -1 || errno != ECHILD);
		
	}
	else
		printf("Need argument!!!\n");
}