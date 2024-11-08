/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:37:21 by aruckenb          #+#    #+#             */
/*   Updated: 2024/11/06 09:19:15 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	other_tasks(t_data *data, t_pedo *philo)
{
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
	{
		philo_dead(data, philo);
		return (1);
	}
	if (data->must_eat_time != 0 && philo->meals_eaten == data->must_eat_time)
	{
		if (philo_full(data, philo) == 1)
			return (1);
	}
	if (philo->fin_eating == 1)
	{
		if (philo_sleep(data, philo) == 1)
			return (1);
	}
	if (philo->thinking == 0 || (philo->thinking == 0
			&& philo->fin_eating == 1))
	{
		if (dead_or_alive(philo, data, 0) == 1)
			return (1);
		if (thinking(data, philo, data->think_time) == 1)
			return (1);
	}
	return (0);
}

void	routine_loop(t_data *data, t_pedo *philo)
{
	while (1)
	{
		if (dead_or_alive(philo, data, 0) == 1)
			break ;
		if (other_tasks(data, philo) == 1)
			break ;
		if (philo->fin_eating == 0)
		{
			if (dead_or_alive(philo, data, 0) == 1)
				break ;
			if (philo->philo_id % 2 == 0)
			{
				if (even(data, philo) == 1)
					break ;
			}
			else
			{
				if (odd(data, philo) == 1)
					break ;
			}
		}
	}
}

void	*routine(void *arg)
{
	t_pedo	*philo;

	philo = (t_pedo *)arg;
	time_current_death(philo, philo->data);
	if (philo->data->num_philo == 1)
		solo_philo(philo->data, philo);
	else if (philo->data->num_philo % 2 == 0)
	{
		if (even_start(philo->data, philo) == 1)
			return (0);
	}
	else
	{
		if (odd_start(philo->data, philo) == 1)
			return (0);
	}
	routine_loop(philo->data, philo);
	return (0);
}

void	setter(t_data *data, t_pedo *philo)
{
	data->thread_id = malloc(sizeof(pthread_t) * data->num_philo + 1);
	if (!data->thread_id)
	{
		write(2, "Error: Memory Allocation Failed\n", 33);
		free_all_data(data);
		return ;
	}
	if (mutex_creator(data) == 2)
	{
		free_all_data(data);
		return ;
	}
	if (fork_mutex(data, philo, 0) == 2)
	{
		free_all_data(data);
		return ;
	}
	if (thread_creation(data, philo, 0) == 1)
		pthread_mutex_destroy(&philo->l_fork);
	pthread_mutex_destroy(&data->full_lock);
	pthread_mutex_destroy(&data->dead_or_alive_lock);
	pthread_mutex_destroy(&data->print_lock_thinking);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->exit);
	free_all_data(data);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_pedo	*philo;	

	if (argc != 5 && argc != 6)
		return (write(2, "Error: Not the right Arguments!\n", 33));
	data = malloc(sizeof(t_data));
	if (!data)
		return (write(2, "Error: Memory Allocation Failed\n", 33));
	if (number_of_philo(data, argv) == 1)
		return (write(2, "Error: Invalid Numbers", 23));
	philo = malloc(sizeof(t_pedo) * data->num_philo);
	if (!philo)
		return (write(2, "Error: Memory Allocation Failed\n", 33));
	data->philo = philo;
	philo_assign(philo, data);
	if (task_times(data, argv, argc) == 1)
		return (write(2, "Error: Invalid Numbers", 23));
	return (time_start(&data->time_stamp), setter(data, philo), 0);
}
