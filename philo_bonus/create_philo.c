/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:11:32 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/22 13:14:45 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_philo(t_philos *philo)
{
	int	i;

	while (1)
	{
		if (waitpid(-1, NULL, WNOHANG))
		{
			i = 0;
			while (i < philo->arg_info.n_of_p)
			{
				kill(philo[i].fork_id, SIGKILL);
				usleep(300000);
				i++;
			}
			break ;
		}
		usleep(50);
	}
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT_MSG);
	sem_close(philo->fork);
	sem_close(philo->print_msg);
	free(philo);
	exit(EXIT_SUCCESS);
}

void	*start_philo(t_arg args_info, t_philos *philosopher)
{
	int	i;

	i = 0;
	if_there_is_one_philo(philosopher, args_info);
	while (i < args_info.n_of_p)
	{
		philosopher[i].fork_id = fork();
		if (philosopher[i].fork_id == 0)
		{
			philosopher[i].id = i + 1;
			philosopher[i].arg_info = args_info;
			philosopher[i].time = get_time();
			philosopher[i].time_of_last_meal = get_time();
			philosopher[i].fork = philosopher->fork;
			philosopher[i].print_msg = philosopher->print_msg;
			routine(&philosopher[i]);
		}
		if (philosopher[i].fork_id == -1)
			return (write(1, "can't create process!!\n", 23), exit(0), NULL);
		i++;
	}
	return (0);
}

void	if_there_is_one_philo(t_philos *philo, t_arg args)
{
	philo->arg_info = args;
	if (philo->arg_info.n_of_p == 1)
	{
		philo->fork_id = fork();
		if (philo->fork_id == 0)
		{
			philo->time = get_time();
			sem_wait(philo->fork);
			printf("%lldms philo %d is take a fork 🍴\n", \
				get_time() - philo->time, 1);
			ft_usleep(philo->arg_info.t_t_d, get_time(), NULL);
			printf("%lldms philo %d died 💀🎃\n", \
				get_time() - philo->time, 1);
			sem_close(philo->fork);
			sem_close(philo->print_msg);
			free(philo);
			exit(EXIT_SUCCESS);
		}
		wait_philo(philo);
	}
}

void	init_sem(t_philos *philos, int nbr_of_philo)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT_MSG);
	philos->fork = sem_open(SEM_FORK, O_CREAT | O_EXCL, 0777, nbr_of_philo);
	philos->print_msg = sem_open(SEM_PRINT_MSG, O_CREAT | O_EXCL, 0777, 1);
	if (philos->fork == SEM_FAILED || philos->print_msg == SEM_FAILED)
	{
		printf("error : semaphore was not created!!\n");
		free(philos);
		exit(EXIT_FAILURE);
	}
}
