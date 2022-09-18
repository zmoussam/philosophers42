/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:02:01 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/18 19:02:26 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_arg		args_to_info;
	t_philos	*philosophers;

	if (argc == 5 || argc == 6)
	{
		parssing(argv);
		get_arg_to_int(argv, &args_to_info);
		philosophers = \
			(t_philos *)malloc(sizeof(t_philos) * args_to_info.n_of_p);
		if (philosophers == NULL)
		{
			write(1, "memory was not allocated!!\n", 27);
			exit(0);
		}
		init_sem(philosophers, args_to_info.n_of_p);
		if_there_is_one_philo(philosophers, args_to_info);
		create_philo(args_to_info, philosophers);
		wait_philo(philosophers);
	}
	else
		printf("Need argument!!!\n");
	return (0);
}
