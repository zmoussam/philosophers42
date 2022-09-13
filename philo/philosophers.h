/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:57:38 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/13 20:32:57 by zmoussam         ###   ########.fr       */
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
int			create_philosophers(t_arg philo_info, t_philos *philosophers);
void		init_id(t_philos *philo_info, int nbr_of_philo);
void		init_left_forks_and_msg(t_philos *philos, int nbr_of_forks);
void		init_right_forks(t_philos *philos, int nbr_of_philo);
void		ft_pthread_join(int nbr_of_philosophers, t_philos *philos);
void		*routine(void *arg);
long long	get_time(void);
void		ft_usleep(int time_to_wait, long long execution_time);
void		init_mutex_msg(t_philos *philosophers);
void		ft_free(t_philos *philo_info);
void		check_t_t_d(t_philos *philo);
int			take_left_fork(t_philos *philo);
void		take_right_fork(t_philos *philo);
int			is_eating(t_philos *philo);
void		is_sleeping(t_philos *philo);
void		is_thinking(t_philos *philo);

#endif
