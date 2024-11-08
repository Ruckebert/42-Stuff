/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:36:12 by aruckenb          #+#    #+#             */
/*   Updated: 2024/11/07 13:25:10 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_assign(t_pedo *philo, t_data *data)
{
	int	i;

	data->dead_philo = 0;
	i = -1;
	while (++i < data->num_philo)
	{
		ft_bzero(&philo[i], sizeof(t_pedo));
		philo[i].philo_id = i + 1;
		philo[i].data = data;
		philo[i].start_of_death = 0;
	}
}

int	number_of_philo(t_data *data, char *argv[])
{
	ft_bzero(data, sizeof(*data));
	if (ft_atoi(argv[1]) <= 0)
		return (1);
	data->num_philo = ft_atoi(argv[1]);
	return (0);
}

void	philo_dead(t_data *data, t_pedo *philo)
{
	if (dead_or_alive(philo, data, 0) == 1)
		return ;
	pthread_mutex_lock(&data->dead_or_alive_lock);
	philo->alive_or_dead = 1;
	pthread_mutex_lock(&data->exit);
	write_message(data, philo, "died\n");
	pthread_mutex_unlock(&data->exit);
	pthread_mutex_lock(&data->print_lock);
	data->dead_philo = 1;
	pthread_mutex_unlock(&data->print_lock);
	pthread_mutex_unlock(&data->dead_or_alive_lock);
	return ;
}

void	odd_forks_unlock(t_pedo *philo)
{
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	even_forks_unlock(t_pedo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}
