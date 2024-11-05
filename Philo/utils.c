/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:40:56 by aruckenb          #+#    #+#             */
/*   Updated: 2024/11/05 15:25:38 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*write_together(char *time_str, char *philo_str,
	char *combined_str, char *message)
{
	size_t	i;
	int		word;

	word = 0;
	i = 0;
	while (i < ft_strlen(time_str))
		combined_str[word++] = time_str[i++];
	combined_str[word++] = ' ';
	i = 0;
	while (i < ft_strlen(philo_str))
		combined_str[word++] = philo_str[i++];
	combined_str[word++] = ' ';
	i = 0;
	while (i < ft_strlen(message))
		combined_str[word++] = message[i++];
	combined_str[word] = '\0';
	return (combined_str);
}

int	write_message(t_data *data, t_pedo *philo, char *message)
{
	char	*time_str;
	char	*philo_id_str;
	char	*combined_message;

	time_str = ft_itoa(time_current(data));
	if (!time_str)
		return (1);
	philo_id_str = ft_itoa(philo->philo_id);
	if (!philo_id_str)
		return (free(time_str), 1);
	combined_message = malloc(ft_strlen(time_str)
			+ 1 + ft_strlen(philo_id_str) + 1 + ft_strlen(message) + 1);
	if (!combined_message)
		return (free(time_str), free(philo_id_str), 1);
	combined_message = write_together(time_str, philo_id_str,
			combined_message, message);
	write(1, combined_message, ft_strlen(time_str)
		+ 1 + ft_strlen(philo_id_str) + 1 + ft_strlen(message) + 1);
	free(time_str);
	free(philo_id_str);
	free(combined_message);
	return (0);
}

void	philo_assign(t_pedo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		ft_bzero(&philo[i], sizeof(t_pedo));
		philo[i].philo_id = i + 1;
		philo[i].data = data;
		philo[i].start_of_death = 0;
	}
}

int	dead_or_alive(t_pedo *philo, t_data *data, int lock_or_fork)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->dead_or_alive_lock);
	while (i < data->num_philo)
	{
		if (data->philo[i].alive_or_dead == 1)
		{
			if (lock_or_fork == 1)
				odd_forks_unlock(philo);
			else if (lock_or_fork == 2)
				even_forks_unlock(philo);
			else if (lock_or_fork == 3)
				pthread_mutex_unlock(philo->r_fork);
			else if (lock_or_fork == 4)
				pthread_mutex_unlock(&philo->l_fork);
			pthread_mutex_unlock(&data->dead_or_alive_lock);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&data->dead_or_alive_lock);
	return (0);
}

int	better_usleep(t_data *data, t_pedo *philo, int time, int lock_or_fork)
{
	long long	start_time;
	long long	elasped_time;

	start_time = time_current(data);
	elasped_time = 0;
	while (elasped_time < time / 1000)
	{
		elasped_time = time_current(data) - start_time;
		if (dead_or_alive(philo, data, lock_or_fork) == 1)
			return (1);
		if ((time_current(data) - philo->start_of_death) >= data->death_time)
		{
			if (lock_or_fork == 1)
				odd_forks_unlock(philo);
			else if (lock_or_fork == 2)
				even_forks_unlock(philo);
			return (philo_dead(data, philo), 1);
		}
		usleep(10);
	}
	return (0);
}
