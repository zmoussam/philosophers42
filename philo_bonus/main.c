/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:02:01 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 11:07:37 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_arg		args;
	t_philos	*philos;

	if (argc == 5 || argc == 6)
	{
		parssing(argv);
		get_arg_to_int(argv, &args);
		philos = (t_philos *)malloc(sizeof(t_philos) * args.n_of_p);
		if (philos == NULL)
			return (write(1, "memory was not allocated!!\n", 27));
		init_sem(philos, args.n_of_p);
		start_philo(args, philos);
		wait_philo(philos);
	}
	else
		printf("Need argument!!!\n");
	return (0);
}
