/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:56:44 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 13:02:13 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	parssing(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] > 32)
			{
				printf("error : arg invalide!!\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_empty_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			write(1, "empty argument!!\n", 17);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	get_arg_to_int(char **argv, t_arg *philos_info)
{
	check_empty_arg(argv);
	philos_info->n_of_p = ft_atoi(argv[1]);
	if (philos_info->n_of_p == 0)
		exit(EXIT_FAILURE);
	philos_info->t_t_d = ft_atoi(argv[2]);
	philos_info->t_t_e = ft_atoi(argv[3]);
	philos_info->t_t_s = ft_atoi(argv[4]);
	philos_info->n_o_t_e_p_m_e = 0;
	if (argv[5] && argv[0] != '\0')
	{
		philos_info->n_o_t_e_p_m_e = ft_atoi(argv[5]);
		if (philos_info->n_o_t_e_p_m_e == 0)
			exit(EXIT_FAILURE);
	}
	if (philos_info->n_of_p < 0 || philos_info->t_t_d < 0
		|| philos_info->t_t_e < 0 || philos_info->t_t_s < 0
		|| philos_info->n_o_t_e_p_m_e < 0)
	{
		printf("error : arg invalide!! --> nombre long\n");
		exit(EXIT_FAILURE);
	}
}
