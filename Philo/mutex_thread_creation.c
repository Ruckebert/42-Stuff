/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_thread_creation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:55 by aruckenb          #+#    #+#             */
/*   Updated: 2024/11/05 11:22:00 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all_data(t_data *data)
{
	if (data->thread_id)
		free(data->thread_id);
	if (data->philo)
		free(data->philo);
	if (data)
		free(data);
}

int	thread_creation(t_data *data, t_pedo *philo, int i)
{
	while (i < data->num_philo)
	{
		if (pthread_create(&data->thread_id[i], NULL, &routine, &philo[i]) != 0)
		{
			write(2, "Error: Thread Creation Failed!\n", 32);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_join(data->thread_id[i], NULL) != 0)
		{
			write(2, "Error: Thread Joining Failed!\n", 31);
			return (1);
		}
		i++;
	}
	return (0);
}

int	mutex_creator(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (write(2, "Error: Mutext Init has failed\n", 31));
	if (pthread_mutex_init(&data->print_lock_thinking, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_lock);
		return (write(2, "Error: Mutext Init has failed\n", 31));
	}
	if (pthread_mutex_init(&data->dead_or_alive_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_lock);
		pthread_mutex_destroy(&data->print_lock_thinking);
		return (write(2, "Error: Mutext Init has failed\n", 31));
	}
	if (pthread_mutex_init(&data->full_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_lock);
		pthread_mutex_destroy(&data->print_lock_thinking);
		pthread_mutex_destroy(&data->dead_or_alive_lock);
		return (write(2, "Error: Mutext Init has failed\n", 31));
	}
	return (0);
}

int	fork_mutex(t_data *data, t_pedo *philo, int i)
{
	if (pthread_mutex_init(&data->exit, NULL) != 0)
	{
		pthread_mutex_destroy(&data->dead_or_alive_lock);
		pthread_mutex_destroy(&data->print_lock);
		pthread_mutex_destroy(&data->print_lock_thinking);
		pthread_mutex_destroy(&data->full_lock);
		return (write(2, "Error: Mutext Init has failed\n", 31));
	}
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&philo[i].l_fork, NULL) != 0)
		{
			while (i > 0)
				pthread_mutex_destroy(&philo[--i].l_fork);
			pthread_mutex_destroy(&data->exit);
			pthread_mutex_destroy(&data->dead_or_alive_lock);
			pthread_mutex_destroy(&data->print_lock);
			pthread_mutex_destroy(&data->print_lock_thinking);
			pthread_mutex_destroy(&data->full_lock);
			return (write(2, "Error: Mutext Init has failed\n", 31));
		}
		i++;
	}
	assign_right_fork(data, philo);
	return (0);
}

void	assign_right_fork(t_data *data, t_pedo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (i == data->num_philo - 1)
			philo[i].r_fork = &philo[0].l_fork;
		else
			philo[i].r_fork = &philo[i + 1].l_fork;
		i++;
	}
}
