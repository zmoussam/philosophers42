/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:51:48 by zmoussam          #+#    #+#             */
/*   Updated: 2022/09/13 17:14:18 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t died;
void ft_usleep(int time_to_wait, long long execution_time)
{ 
    while(1)
    {
        if((get_time() - execution_time) >= time_to_wait)
            break;
    }
}
void *routine(void *arg)
{
    t_philos philo;
    philo = *(t_philos *)arg;
    
    if(philo.id % 2 == 0)
        ft_usleep(30, get_time());
    
   while(1)
   {
        pthread_mutex_lock(philo.left_fork);
        
        if((get_time() - philo.time_of_last_meal) >= philo.arg_info.t_t_d)
        {
            pthread_mutex_lock(philo.msg);
            
            printf("%lldms philo %d died 💀🎃\n", (get_time() - philo.time) , philo.id);
            exit(0);
            
            pthread_mutex_unlock(philo.msg);
        }
        
        pthread_mutex_lock(philo.msg);
        printf("%lldms philo %d has taken a fork 🍴\n",(get_time() - philo.time), philo.id);  
        pthread_mutex_unlock(philo.msg);
        if(philo.arg_info.n_of_p == 1)
        {
            ft_usleep(philo.arg_info.t_t_d, get_time());
            printf("%lldms philo %d died 💀🎃\n",(get_time() - philo.time), philo.id);
            break;
        }
        pthread_mutex_lock(philo.right_fork);
        if((get_time() - philo.time_of_last_meal) >= philo.arg_info.t_t_d)
        {
            pthread_mutex_lock(philo.msg);
            printf("%lldms philo %d died 💀🎃\n",(get_time() - philo.time), philo.id);
            exit(0);
            pthread_mutex_unlock(philo.msg);
        }
        
        pthread_mutex_lock(philo.msg);
        printf("%lldms philo %d has taken a fork 🍴\n",(get_time() - philo.time), philo.id);
        pthread_mutex_unlock(philo.msg);
         
       philo.time_of_last_meal = get_time();
       
       pthread_mutex_lock(philo.msg);
       printf("%lldms philo %d is eating 🍽️ 🍔\n",(get_time() - philo.time), philo.id);
       pthread_mutex_unlock(philo.msg);
        
       ft_usleep(philo.arg_info.t_t_e, get_time());
       
       pthread_mutex_unlock(philo.left_fork);
       pthread_mutex_unlock(philo.right_fork);
       
       if(philo.arg_info.check_last_arg == 1)
       {
           philo.arg_info.n_o_t_e_p_m_e--;
           if(philo.arg_info.n_o_t_e_p_m_e == 0)
                break;
       }
       
        pthread_mutex_lock(philo.msg);
        printf("%lldms philo %d is sleeping 🥱 😴\n",(get_time() - philo.time), philo.id);
        pthread_mutex_unlock(philo.msg);
        
       ft_usleep(philo.arg_info.t_t_s, get_time());
       
        pthread_mutex_lock(philo.msg);
        printf("%lldms philo %d is thinking 🤔 🤔\n",(get_time() - philo.time) , philo.id);
        pthread_mutex_unlock(philo.msg);
       
        if((get_time() - philo.time_of_last_meal) >= philo.arg_info.t_t_d)
        {
            pthread_mutex_lock(philo.msg);
            printf("%lldms philo %d died 💀🎃\n",(get_time() - philo.time), philo.id);
            exit(0);
            pthread_mutex_unlock(philo.msg);
        }

   }
return NULL;
}

