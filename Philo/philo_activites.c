/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:44:48 by aruckenb          #+#    #+#             */
/*   Updated: 2024/11/05 13:35:47 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_full(t_data *data, t_pedo *philo)
{
	pthread_mutex_lock(&data->dead_or_alive_lock);
	data->full_philos++;
	if (data->full_philos == data->num_philo)
	{
		pthread_mutex_lock(&data->print_lock_thinking);
		philo->alive_or_dead = 1;
		pthread_mutex_unlock(&data->print_lock_thinking);
		pthread_mutex_unlock(&data->dead_or_alive_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->dead_or_alive_lock);
	return (0);
}

int	eating(t_data *data, t_pedo *philo, int even_or_odd)
{
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
	{
		if (even_or_odd == 1)
			odd_forks_unlock(philo);
		else
			even_forks_unlock(philo);
		philo_dead(data, philo);
		return (1);
	}
	if (dead_or_alive(philo, data, even_or_odd) == 1)
		return (1);
	pthread_mutex_lock(&data->print_lock);
	write_message(data, philo, "is eating\n");
	pthread_mutex_unlock(&data->print_lock);
	if (dead_or_alive(philo, data, even_or_odd) == 1)
		return (1);
	time_current_death(philo, data);
	if (better_usleep(data, philo, data->eat_time, even_or_odd) == 1)
		return (1);
	philo->fin_eating = 1;
	philo->meals_eaten++;
	return (0);
}

int	philo_sleep(t_data *data, t_pedo *philo)
{
	philo->thinking = 0;
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
	{
		philo_dead(data, philo);
		return (1);
	}
	if (dead_or_alive(philo, data, 0) == 1)
		return (1);
	pthread_mutex_lock(&data->print_lock_thinking);
	write_message(data, philo, "is sleeping\n");
	pthread_mutex_unlock(&data->print_lock_thinking);
	if (dead_or_alive(philo, data, 0) == 1)
		return (1);
	if (better_usleep(data, philo, data->sleep_time, 0) == 1)
		return (1);
	philo->fin_eating = 0;
	return (0);
}

int	thinking(t_data *data, t_pedo *philo, int time)
{
	philo->thinking = 1;
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
	{
		philo_dead(data, philo);
		return (1);
	}
	if (dead_or_alive(philo, data, 0) == 1)
		return (1);
	pthread_mutex_lock(&data->print_lock_thinking);
	write_message(data, philo, "is thinking\n");
	pthread_mutex_unlock(&data->print_lock_thinking);
	if (dead_or_alive(philo, data, 0) == 1)
		return (1);
	if (better_usleep(data, philo, time, 0) == 1)
		return (1);
	return (0);
}
