/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:46:21 by aruckenb          #+#    #+#             */
/*   Updated: 2024/09/19 13:14:46 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_data t_data;

//Assign a data structure to each of the philos?
typedef struct s_pedo
{
	t_data *data;
	int philo_id;
	long long start_of_death;
	
	/*Maybe Move this down to data*/
	int	fork_equip;
	int	fin_eating;
	int thinking;
	int	meals_eaten;
	int	alive_or_dead;

	pthread_mutex_t lock; 
	pthread_mutex_t fork; 

}	t_pedo;

typedef struct s_data
{
	t_pedo 		*philo;
	int 		num_philo;
	long long	time_stamp;
	int			full_philos;

	/*Philo times*/
	long long	death_time;
	int			eat_time;
	int			sleep_time;
	int			must_eat_time;

	pthread_t	*thread_id;
	
}	t_data;


/*Utils Functions*/
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);

#endif
