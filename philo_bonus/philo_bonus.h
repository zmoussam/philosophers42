/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:55:10 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/16 16:35:48 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<sys/time.h>
# include<sys/wait.h>
# include<sys/types.h>
# include<unistd.h>
# include<signal.h>
# include<errno.h>
# include <semaphore.h>
# include<fcntl.h>    //For O_* constants
# include<sys/stat.h> // For mode constants

#define SEM_NAME_1 "/SEM_1"
#define SEM_NAME_2 "/SEM_2"

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
	int				count_meal;
	long			time_of_last_meal;
	long			time;
	t_arg			arg_info;
	int				fork_id;
}	t_philos;

void		parssing(char **argv);
void		get_arg_to_int(char **argv, t_arg *philos_info);
void		ft_usleep(int time_to_wait, long long execution_time);
long long	get_time(void);
void		routine(t_philos *philosopher, sem_t *forks);
void		create_philo(t_arg args_info, t_philos *philosophers, sem_t *f);

#endif