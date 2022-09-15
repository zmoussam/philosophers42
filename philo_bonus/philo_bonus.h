/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:55:10 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/15 19:12:50 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<sys/time.h>
# include<sys/wait.h>
# include<unistd.h>
# include<errno.h>
#include <semaphore.h>

# include "../libft/libft.h"

typedef struct t_arg{
	int	n_of_p;
	int	t_t_d;
	int	t_t_e;
	int	t_t_s;
	int	n_o_t_e_p_m_e;
	int	check_last_arg;
}	t_arg;
typedef struct t_philosopher{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*msg;
	int				count_meal;
	long			time_of_last_meal;
	pthread_t		philo;
	long			time;
	t_arg			arg_info;
}	t_philos;

void		parssing(char **argv);
void		get_arg_to_int(char **argv, t_arg *philos_info);
void		ft_usleep(int time_to_wait, long long execution_time);
long long	get_time(void);
void		routine(int i, t_arg args_to_info, long long time);
void	create_philo(t_arg args_info);

#endif