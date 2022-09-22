/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:55:10 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 01:09:41 by zmoussam         ###   ########.fr       */
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
# define SEM_FORK "/forks"
# define SEM_PRINT_MSG "/print_msg"
# include "../libft/libft.h"

typedef struct t_arg{
	int	n_of_p;
	int	t_t_d;
	int	t_t_e;
	int	t_t_s;
	int	n_o_t_e_p_m_e;
}	t_arg;
typedef struct t_philosopher{
	int				id;
	sem_t			*fork;
	sem_t			*print_msg;
	long long		time_of_last_meal;
	long long		time;
	t_arg			arg_info;
	int				fork_id;
}	t_philos;

void		parssing(char **argv);
void		get_arg_to_int(char **argv, t_arg *philos_info);
void		ft_usleep(int time_to_sleep, long long exec_time, t_philos *philo);
void		check_t_t_d(t_philos *philo);
long long	get_time(void);
void		routine(t_philos *philosopher);
void		*start_philo(t_arg args_info, t_philos *philosophers);
void		if_there_is_one_philo(t_philos *philo, t_arg atgs);
void		init_sem(t_philos *philos, int nbr_of_philo);
void		wait_philo(t_philos *philo);
void		take_first_fork(t_philos *philosopher);
void		take_second_fork(t_philos *philosopher);
int			is_eating(t_philos *philosopher);
void		is_sleeping(t_philos *philosopher);
void		is_thinking(t_philos *philosopher);

#endif