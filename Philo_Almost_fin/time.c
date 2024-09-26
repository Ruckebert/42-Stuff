/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:41:51 by aruckenb          #+#    #+#             */
/*   Updated: 2024/09/25 15:56:15 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

//Time Checker and Creation
void	time_start(t_data *data, long long  *time_stamp)
{
	struct timeval time;
	
	if (gettimeofday(&time, NULL) == -1)
		exit(1);
	*time_stamp = (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000));
}
long long	time_current(t_data *data)
{
	struct	timeval time;
	long long current_time;
	
	current_time = 0;
	if (gettimeofday(&time, NULL) == -1)
		exit(1);
	current_time = (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000)) - data->time_stamp;
	return (current_time);
}
void	time_current_death(t_pedo *philo, t_data *data)
{
	struct	timeval time;

	if (gettimeofday(&time, NULL) == -1)
		exit(1);
	philo->start_of_death = (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000)) - data->time_stamp;
}
void	task_times(t_data *data, char *argv[], int argc)
{
	data->death_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]) * 1000;
	data->sleep_time = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data->must_eat_time = ft_atoi(argv[5]);
}