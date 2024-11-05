/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:41:51 by aruckenb          #+#    #+#             */
/*   Updated: 2024/11/05 12:19:09 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_start(long long *time_stamp)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		exit(1);
	*time_stamp = (((long long)time.tv_sec * 1000)
			+ ((long long)time.tv_usec / 1000));
}

long long	time_current(t_data *data)
{
	struct timeval	time;
	long long		current_time;

	current_time = 0;
	if (gettimeofday(&time, NULL) == -1)
		exit(1);
	current_time = (((long long)time.tv_sec * 1000)
			+ ((long long)time.tv_usec / 1000)) - data->time_stamp;
	return (current_time);
}

void	time_current_death(t_pedo *philo, t_data *data)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		exit(1);
	philo->start_of_death = (((long long)time.tv_sec * 1000)
			+ ((long long)time.tv_usec / 1000)) - data->time_stamp;
}

int	absolute(int value)
{
	if (value < 0)
		value *= -1;
	return (value);
}

int	task_times(t_data *data, char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i <= 3)
	{
		if (ft_atoi(argv[i + 1]) <= 0)
			return (1);
		i++;
	}
	if (ft_atoi(argv[2]) < 0)
		return (1);
	data->death_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]) * 1000;
	data->sleep_time = ft_atoi(argv[4]) * 1000;
	if (data->eat_time == data->sleep_time)
		data->think_time = data->eat_time;
	else
		data->think_time = absolute(data->eat_time - data->sleep_time);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
			return (1);
		data->must_eat_time = ft_atoi(argv[5]);
	}
	return (0);
}
