/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rountine_tasks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:42:24 by aruckenb          #+#    #+#             */
/*   Updated: 2024/11/05 15:26:17 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	even(t_data *data, t_pedo *philo)
{
	philo->thinking = 0;
	pthread_mutex_lock(&philo->l_fork);
	if (dead_or_alive(philo, data, 4) == 1)
		return (1);
	pthread_mutex_lock(&data->print_lock);
	write_message(data, philo, "has taken a fork\n");
	pthread_mutex_unlock(&data->print_lock);
	if (dead_or_alive(philo, data, 4) == 1)
		return (1);
	pthread_mutex_lock(philo->r_fork);
	if (dead_or_alive(philo, data, 2) == 1)
		return (1);
	pthread_mutex_lock(&data->print_lock);
	write_message(data, philo, "has taken a fork\n");
	pthread_mutex_unlock(&data->print_lock);
	if (dead_or_alive(philo, data, 2) == 1)
		return (1);
	if (eating(data, philo, 2) == 1)
		return (1);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	return (0);
}

int	odd(t_data *data, t_pedo *philo)
{
	philo->thinking = 0;
	pthread_mutex_lock(philo->r_fork);
	if (dead_or_alive(philo, data, 3) == 1)
		return (1);
	pthread_mutex_lock(&data->print_lock);
	write_message(data, philo, "has taken a fork\n");
	pthread_mutex_unlock(&data->print_lock);
	if (dead_or_alive(philo, data, 3) == 1)
		return (1);
	pthread_mutex_lock(&philo->l_fork);
	if (dead_or_alive(philo, data, 1) == 1)
		return (1);
	pthread_mutex_lock(&data->print_lock);
	write_message(data, philo, "has taken a fork\n");
	pthread_mutex_unlock(&data->print_lock);
	if (dead_or_alive(philo, data, 1) == 1)
		return (1);
	if (eating(data, philo, 1) == 1)
		return (1);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

void	solo_philo(t_data *data, t_pedo *philo)
{
	philo->thinking = 0;
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&data->print_lock);
	write_message(data, philo, "has taken a fork\n");
	pthread_mutex_unlock(&data->print_lock);
	while (1)
	{
		if ((time_current(data) - philo->start_of_death) >= data->death_time)
		{
			pthread_mutex_unlock(&philo->l_fork);
			philo_dead(data, philo);
			break ;
		}
	}
}

int	even_start(t_data *data, t_pedo *philo)
{
	philo->thinking = 0;
	if (philo->philo_id % 2 == 0)
	{
		if (even(data, philo) == 1)
			return (1);
	}
	else
	{
		if (thinking(data, philo, data->think_time) == 1)
			return (1);
	}
	if (data->eat_time == data->sleep_time)
		data->think_time = 0;
	return (0);
}

int	odd_start(t_data *data, t_pedo *philo)
{
	philo->thinking = 0;
	if (philo->philo_id == data->num_philo)
	{
		if (thinking(data, philo, data->think_time * 2) == 1)
			return (1);
	}
	else if (philo->philo_id % 2 == 1)
	{
		if (odd(data, philo) == 1)
			return (1);
	}
	else
	{
		if (thinking(data, philo, data->think_time) == 1)
			return (1);
	}
	if (data->eat_time == data->sleep_time)
		data->think_time = data->think_time;
	return (0);
}
