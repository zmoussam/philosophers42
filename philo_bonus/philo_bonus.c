/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:02:01 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/16 18:01:08 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"


int main(int argc, char **argv)
{
    t_arg		args_to_info;
    t_philos	*philo_infos;
	sem_t *forks = NULL;
	int i;
	int id;
	long long time;
	i = 0;
    if (argc == 5 || argc == 6)
	{
		parssing(argv);
		get_arg_to_int(argv, &args_to_info);
		philo_infos = \
			(t_philos *)malloc(sizeof(t_philos) * args_to_info.n_of_p);
		create_philo(args_to_info, philo_infos, forks);
		// while(waitpid(-1, NULL, WNOHANG) != -1 || errno != ECHILD);
        sem_unlink(SEM_NAME_1);
		sem_close(forks);
	}
	else
		printf("Need argument!!!\n");
}