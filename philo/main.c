/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:56:50 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 01:27:15 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_philos *philo_info)
{
	int	nbr_of_philo;
	int	i;

	i = 0;
	pthread_mutex_destroy(philo_info[i].meals);
	pthread_mutex_destroy(philo_info[i].msg);
	pthread_mutex_destroy(philo_info[i].die);
	nbr_of_philo = philo_info->arg_info.n_of_p;
	while (i < philo_info->arg_info.n_of_p)
	{
		pthread_mutex_destroy(philo_info[i].left_fork);
		free(philo_info[i].left_fork);
		i++;
	}
	free(philo_info->msg);
	free(philo_info->die);
	free(philo_info->meals);
	free(philo_info->check_die);
	free(philo_info->count_meal);
	free(philo_info);
}

void	wait_philosophers(t_philos *philos, int nbr_of_meal)
{
	while (1)
	{
		pthread_mutex_lock(philos->die);
		if (*(philos->check_die) == 0)
			break ;
		pthread_mutex_unlock(philos->die);
		pthread_mutex_lock(philos->meals);
		if (*(philos->count_meal) == nbr_of_meal)
			break ;
		pthread_mutex_unlock(philos->meals);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	t_arg		args;
	t_philos	*philos;

	if (argc == 5 || argc == 6)
	{
		if (!parssing(argv) || !(get_arg_to_int(argv, &args)))
			return (0);
		philos = (t_philos *)malloc(sizeof(t_philos) * args.n_of_p);
		if (philos == NULL)
			return (write(1, "memory was not allocated!!\n", 27));
		if (init_philo(philos, args) || start_philosophers(philos))
			return (0);
		wait_philosophers(philos, args.n_of_p);
		ft_free(philos);
	}
	else
		printf("Need argument!!!\n");
}
