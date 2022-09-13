/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:56:50 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/13 20:37:02 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include<pthread.h>
#include <stdlib.h>

void    ft_free(t_philos *philo_info)
{
    int nbr_of_philo;
    int i;
    
    i = 0;
    free(philo_info->msg);
    nbr_of_philo = philo_info->arg_info.n_of_p;
    while(i < nbr_of_philo)
    {
        free(philo_info[i].left_fork);
        pthread_mutex_destroy(philo_info[i].left_fork);
        pthread_mutex_destroy(philo_info[i].msg);
        i++;
    }
    free(philo_info);
    
}
int main(int argc, char **argv)
{
    t_arg args_to_info;
    t_philos *philo_infos;
    int i;
    i = 0;
    if(argc == 5 || argc == 6)
    {
        parssing(argv);
        get_arg_to_int(argv, &args_to_info);
        philo_infos = (t_philos *)malloc(sizeof(t_philos) * args_to_info.n_of_p);
        init_id(philo_infos, args_to_info.n_of_p);
        init_left_forks_and_msg(philo_infos, args_to_info.n_of_p);
        init_right_forks(philo_infos, args_to_info.n_of_p);
        create_philosophers(args_to_info, philo_infos);
        ft_pthread_join(args_to_info.n_of_p, philo_infos);
        ft_free(philo_infos);
    } 
}