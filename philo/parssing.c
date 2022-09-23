/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:32:57 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 13:01:35 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parssing(char **argv)
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
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_empty_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			write(1, "empty argument!!\n", 17);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_arg_to_int(char **argv, t_arg *philos_info)
{
	if (!check_empty_arg(argv))
		return (0);
	philos_info->n_of_p = ft_atoi(argv[1]);
	if (philos_info->n_of_p == 0)
		return (0);
	philos_info->t_t_d = ft_atoi(argv[2]);
	philos_info->t_t_e = ft_atoi(argv[3]);
	philos_info->t_t_s = ft_atoi(argv[4]);
	philos_info->n_o_t_e_p_m_e = 0;
	if (argv[5] && argv[0] != '\0')
	{
		philos_info->n_o_t_e_p_m_e = ft_atoi(argv[5]);
		if (philos_info->n_o_t_e_p_m_e == 0)
			return (0);
	}
	if (philos_info->n_of_p < 0 || philos_info->t_t_d < 0
		|| philos_info->t_t_e < 0 || philos_info->t_t_s < 0
		|| philos_info->n_o_t_e_p_m_e < 0)
	{
		printf("error : arg invalide!! --> nombre long\n");
		return (0);
	}
	return (1);
}
