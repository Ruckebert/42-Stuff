/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:44:48 by aruckenb          #+#    #+#             */
/*   Updated: 2024/09/25 13:28:15 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_full(t_data *data, t_pedo *philo)
{
	pthread_mutex_lock(&data->dead_or_alive_lock);
	data->full_philos++;
	if (data->full_philos == data->num_philo)
	{
		write(1, "Philosophers are all Full!\n", 28);
		
		pthread_mutex_lock(&data->print_lock_thinking);
		philo->alive_or_dead = 1; //Still a possible data race
		pthread_mutex_unlock(&data->print_lock_thinking);

		pthread_mutex_unlock(&data->dead_or_alive_lock);
		exit_program(data, philo);
	}
	pthread_mutex_unlock(&data->dead_or_alive_lock);
}

void	eating(t_data *data, t_pedo *philo, int even_or_odd)
{	
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
	{
		if (even_or_odd == 1)
		{
			pthread_mutex_unlock(&philo->l_fork);
			pthread_mutex_unlock(&philo->r_fork);
		}
		else
		{
			pthread_mutex_unlock(&philo->r_fork);
			pthread_mutex_unlock(&philo->l_fork);
		}
		philo_dead(data, philo);
	}
	
	dead_or_alive(philo, data, even_or_odd);
	pthread_mutex_lock(&data->print_lock);
	write_message(data, philo, "is eating\n", 0);
	pthread_mutex_unlock(&data->print_lock);
	dead_or_alive(philo, data, even_or_odd);
	
	better_usleep(data, philo, data->eat_time, even_or_odd);
	
	philo->fin_eating = 1;
	philo->meals_eaten++;
	time_current_death(philo, data);
}

void	philo_sleep(t_data *data, t_pedo *philo)
{
	philo->thinking = 0;

	if ((time_current(data) - philo->start_of_death) >= data->death_time)
		philo_dead(data, philo);
	
	
	dead_or_alive(philo, data, 0);
	pthread_mutex_lock(&data->print_lock_thinking);
	write_message(data, philo, "is sleeping\n", 0);
	pthread_mutex_unlock(&data->print_lock_thinking);
	dead_or_alive(philo, data, 0);
	better_usleep(data, philo, data->sleep_time, 0);
	
	philo->fin_eating = 0;
}

void	thinking(t_data *data, t_pedo *philo, int time)
{
	philo->thinking = 1;
	
	dead_or_alive(philo, data, 0);
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
		philo_dead(data, philo);
	dead_or_alive(philo, data, 0);
	
	pthread_mutex_lock(&data->print_lock_thinking);
	write_message(data, philo, "is thinking\n", 0);
	pthread_mutex_unlock(&data->print_lock_thinking);

	dead_or_alive(philo, data, 0);
	better_usleep(data, philo, (data->eat_time - time), 0);
}
