/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:02:01 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/18 01:37:12 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"


void	if_there_is_one_philo(t_philos *philo, t_arg args)
{
	philo->arg_info = args;
	if (philo->arg_info.n_of_p == 1)
	{
		philo->fork_id = fork();
		if (philo->fork_id == 0)
		{
			philo->time = get_time();
			printf("%lldms philo %d is take a fork 🍴\n", get_time() - philo->time, 1);
			ft_usleep(philo->arg_info.t_t_d, get_time(), NULL);
			printf("%lldms philo %d died 💀🎃\n", get_time() - philo->time , philo->id);
		  	exit(0);
		}
		wait(NULL);
		exit(0);
	}
}
void	init_sem(t_philos *philos, int nbr_of_philo)
{
	sem_unlink("/forks");
	sem_unlink("/print_msg");
	philos->fork = sem_open("/forks", O_CREAT | O_EXCL, 0777, nbr_of_philo);
	philos->print_msg = sem_open("/print_msg", O_CREAT | O_EXCL, 0777, 1);
	if (philos->fork == SEM_FAILED || philos->print_msg == SEM_FAILED)
	{
		printf("error : semaphore was not created!!\n");
		exit(0);
	}
}
int main(int argc, char **argv)
{
    t_arg		args_to_info;
    t_philos	*philosophers;
	int id;
	
    if (argc == 5 || argc == 6)
	{
		parssing(argv);
		get_arg_to_int(argv, &args_to_info);
		philosophers = \
			(t_philos *)malloc(sizeof(t_philos) * args_to_info.n_of_p);
		if(philosophers == NULL)
			exit(0);
		init_sem(philosophers, args_to_info.n_of_p);
		if_there_is_one_philo(philosophers, args_to_info);
		create_philo(args_to_info, philosophers);
		sem_unlink("/forks");
		sem_close(philosophers->fork);
	}
	else
		printf("Need argument!!!\n");
}