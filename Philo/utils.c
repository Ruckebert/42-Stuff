/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:40:56 by aruckenb          #+#    #+#             */
/*   Updated: 2024/09/25 15:46:37 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_message(t_data *data, t_pedo *philo, char *message, int i)
{
	char	*time_str;
	char	*philo_id_str;
	char	*combined_message;
	int		word;

	word = 0;
	time_str = ft_itoa(time_current(data));
	philo_id_str = ft_itoa(philo->philo_id);
	combined_message = malloc(ft_strlen(time_str) + 1 + ft_strlen(philo_id_str) + 1 + ft_strlen(message) + 1);
	while(i < ft_strlen(time_str))
		combined_message[word++] = time_str[i++];
	combined_message[word++] = ' ';
	i = 0;
	while(i < ft_strlen(philo_id_str))
		combined_message[word++] = philo_id_str[i++];
	combined_message[word++] = ' ';
	i = 0;
	while(i < ft_strlen(message))
		combined_message[word++] = message[i++];
	combined_message[word] = '\0';
	write(1, combined_message, ft_strlen(time_str) + 1 + ft_strlen(philo_id_str) + 1 + ft_strlen(message) + 1);
	free(time_str);
	free(philo_id_str);
	free(combined_message);
}

void	exit_program(t_data *data, t_pedo *philo)
{
	int i;
	//philo->task_done = 1;
	pthread_mutex_lock(&data->exit);

	usleep(200);
	
	i = 0;
	if (philo)
	{
		while (i < data->num_philo)
		{
			pthread_mutex_lock(&data->print_lock);
			if (pthread_mutex_destroy(&philo[i].l_fork) != 0)
				printf("Error Destorying Lock Left Fork\n");
			pthread_mutex_unlock(&data->print_lock);
			i++;
		}
		free(data->philo);
	}
	i = 0;
	if (data->thread_id)
	{
		free(data->thread_id);
	}
	pthread_mutex_unlock(&data->exit);

	pthread_mutex_destroy(&data->full_lock);
	pthread_mutex_destroy(&data->dead_or_alive_lock);
	pthread_mutex_destroy(&data->print_lock_thinking);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->exit);

	if (data)
		free(data);
	exit(0);
}

void	philo_dead(t_data *data, t_pedo *philo)
{
	pthread_mutex_lock(&data->dead_or_alive_lock);
	printf("%lld %d died\n", time_current(data), philo->philo_id);
	philo->alive_or_dead = 1;
	pthread_mutex_unlock(&data->dead_or_alive_lock);
	exit_program(data, philo);
}
void	dead_or_alive(t_pedo *philo, t_data *data, int lock_or_fork)
{
	int i;

	i = 0;
	pthread_mutex_lock(&data->dead_or_alive_lock);
	while (i < philo->data->num_philo)
	{
		if (philo->data->philo[i].alive_or_dead == 1)
		{
			if (lock_or_fork == 1)
			{
				pthread_mutex_unlock(&philo->l_fork);
				pthread_mutex_unlock(&philo->r_fork);
			}
			else if (lock_or_fork == 2)
			{
				pthread_mutex_unlock(&philo->r_fork);
				pthread_mutex_unlock(&philo->l_fork);
			}
			else if (lock_or_fork == 3)
				pthread_mutex_unlock(&philo->r_fork);
			else if (lock_or_fork == 4)
				pthread_mutex_unlock(&philo->l_fork);
			pthread_mutex_unlock(&data->dead_or_alive_lock);
			exit_program(philo->data, philo);
		}
		i++;
	}
	pthread_mutex_unlock(&data->dead_or_alive_lock);
	
}

void 	better_usleep(t_data *data, t_pedo *philo, int time, int lock_or_fork)
{
	long long start_time;
	long long elasped_time;

	start_time = time_current(data);
	elasped_time = 0;
	while (elasped_time < time/1000) 
	{
		elasped_time = time_current(data) - start_time;
		dead_or_alive(philo, data, lock_or_fork);
		if ((elasped_time - philo->start_of_death) >= data->death_time)
		{
			if (lock_or_fork == 1)
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
		usleep(10);
	}
}