/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:57:38 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 01:16:46 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<sys/time.h>
# include<unistd.h>
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
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*die;
	pthread_mutex_t	*meals;
	int				*check_die;
	int				*count_meal;
	long			time_of_last_meal;
	pthread_t		philo;
	long			time;
	t_arg			arg_info;
}	t_philos;

int			parssing(char **argv);
int			get_arg_to_int(char **argv, t_arg *philos_info);
int			start_philosophers(t_philos *philosophers);
int			init_philo(t_philos *philos, t_arg philo_info);
int			init_forks(t_philos *philos);
int			init_mutex(t_philos *philos);
void		*routine(void *arg);
long long	get_time(void);
void		ft_usleep(int time_to_sleep, long long exec_time, t_philos *philo);
void		init_mutex_msg(t_philos *philosophers);
void		ft_free(t_philos *philo_info);
void		check_t_t_d(t_philos *philo);
void		take_left_fork(t_philos *philo);
void		take_right_fork(t_philos *philo);
int			is_eating(t_philos *philo);
void		is_sleeping(t_philos *philo);
void		is_thinking(t_philos *philo);
int			if_there_is_one_philo(t_philos *philo);
void		*routine_for_one(void *arg);
void		wait_philosophers(t_philos *philos, int nbr_of_meal);

#endif
