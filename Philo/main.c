/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:37:21 by aruckenb          #+#    #+#             */
/*   Updated: 2024/09/25 13:14:04 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

//Main rountine
void	*routine(void *arg)
{
	t_pedo *philo = (t_pedo *)arg;
	t_data *data = philo->data;

	philo->thinking = 0;
	time_current_death(philo, data);
	
	if (data->num_philo == 1) 
	{
		pthread_mutex_lock(&philo->l_fork);
			
		pthread_mutex_lock(&data->print_lock);
		write_message(data, philo, "has taken a fork\n", 0);
		pthread_mutex_unlock(&data->print_lock);
		
		while (1)
		{
			if ((time_current(data) - philo->start_of_death) >= data->death_time)
			{
				pthread_mutex_unlock(&philo->l_fork);
            	philo_dead(data, philo);
			}
		}
	}

	//Even
	if (data->num_philo % 2 == 0)
	{
		if (philo->philo_id % 2 == 1)
		{
			pthread_mutex_lock(&philo->l_fork);
			philo->thinking = 0;
			
			pthread_mutex_lock(&data->print_lock);
			write_message(data, philo, "has taken a fork\n", 0);
			pthread_mutex_unlock(&data->print_lock);

			pthread_mutex_lock(&philo->r_fork);
			
			pthread_mutex_lock(&data->print_lock);
			write_message(data, philo, "has taken a fork\n", 0);
			pthread_mutex_unlock(&data->print_lock);
			
			eating(data, philo, 2);
			pthread_mutex_unlock(&philo->r_fork);
			pthread_mutex_unlock(&philo->l_fork);
		}
		else
			thinking(data, philo, 0);
	}
	else
	{ //Odd
		if (philo->philo_id == data->num_philo)
			thinking(data, philo, -(data->eat_time));
		else if (philo->philo_id % 2 == 1)
		{
			pthread_mutex_lock(&philo->r_fork);
			philo->thinking = 0;
			
			pthread_mutex_lock(&data->print_lock);
			write_message(data, philo, "has taken a fork\n", 0);
			pthread_mutex_unlock(&data->print_lock);
			
			pthread_mutex_lock(&philo->l_fork);
			
			pthread_mutex_lock(&data->print_lock);
			write_message(data, philo, "has taken a fork\n", 0);
			pthread_mutex_unlock(&data->print_lock);
	
			eating(data, philo, 1);
			pthread_mutex_unlock(&philo->l_fork);
			pthread_mutex_unlock(&philo->r_fork);
		}
		else
			thinking(data, philo, 0);
	}
	
	while (1)
	{	
		if ((time_current(data) - philo->start_of_death) >= data->death_time)
            philo_dead(data, philo);
		if (data->must_eat_time != 0 && philo->meals_eaten == data->must_eat_time)
			philo_full(data, philo);
		if (philo->fin_eating == 1)
			philo_sleep(data, philo);
		if (philo->thinking == 0 || (philo->thinking == 0 && philo->fin_eating == 1))	
		{
			dead_or_alive(philo, data, 0);
			thinking(data, philo, 0);
		} 
		if (philo->fin_eating == 0)
		{
			philo->thinking = 0;
			dead_or_alive(philo, data, 0);
			if (data->num_philo % 2 == 0)
			{	//Even
				pthread_mutex_lock(&philo->l_fork);
			
				dead_or_alive(philo, data, 4);
				pthread_mutex_lock(&data->print_lock);
				write_message(data, philo, "has taken a fork\n", 0);
				pthread_mutex_unlock(&data->print_lock);
				dead_or_alive(philo, data, 4);
				
				pthread_mutex_lock(&philo->r_fork);
				
				dead_or_alive(philo, data, 2);
				pthread_mutex_lock(&data->print_lock);
				write_message(data, philo, "has taken a fork\n", 0);
				pthread_mutex_unlock(&data->print_lock);
				dead_or_alive(philo, data, 2);
				
				eating(data, philo, 2);
				pthread_mutex_unlock(&philo->r_fork);
				pthread_mutex_unlock(&philo->l_fork);
			}
			else
			{
				pthread_mutex_lock(&philo->r_fork);
				philo->thinking = 0;
				
				dead_or_alive(philo, data, 3);
				pthread_mutex_lock(&data->print_lock);
				write_message(data, philo, "has taken a fork\n", 0);
				pthread_mutex_unlock(&data->print_lock);
				dead_or_alive(philo, data, 3);
				
				pthread_mutex_lock(&philo->l_fork);
				
				dead_or_alive(philo, data, 1);
				pthread_mutex_lock(&data->print_lock);
				write_message(data, philo, "has taken a fork\n", 0);
				pthread_mutex_unlock(&data->print_lock);
				dead_or_alive(philo, data, 1);

				eating(data, philo, 1);
				pthread_mutex_unlock(&philo->l_fork);
				pthread_mutex_unlock(&philo->r_fork);
			}
		}
	}
	exit_program(data, philo);
	return (0);
}

//Odd and even to be work on
void	setter(t_data *data, t_pedo *philo)
{
	int i;
	
	//Creating the seperate thread IDS
	data->thread_id = malloc(sizeof(pthread_t) * data->num_philo);
	if (!data->thread_id)
	{
		write(2, "Error: Memory Allocation Failed\n", 33);
		exit_program(data, philo);
	}
	
	//Mutex Creation
	//Redo eveything for when the program for mutex init fails
	i = 0;
	
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
	{
			pthread_mutex_destroy(&philo[--i].l_fork);
		exit(1);
	}
	if (pthread_mutex_init(&data->print_lock_thinking, NULL) != 0)
	{
		write(2, "Error: Mutext Init has failed\n", 31);
		exit(1);
	}
	if (pthread_mutex_init(&data->dead_or_alive_lock, NULL) != 0)
	{
		write(2, "Error: Mutext Init has failed\n", 31);
		exit(1);
	}
	if (pthread_mutex_init(&data->full_lock, NULL) != 0)
	{
		write(2, "Error: Mutext Init has failed\n", 31);
		exit(1);
	}

	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&philo[i].l_fork, NULL) != 0)
		{
			write(2, "Error: Mutext Init has failed\n", 31);
			while (i > 0)
				pthread_mutex_destroy(&philo[--i].l_fork);
			exit(1);
		}
		if (pthread_mutex_init(&data->exit, NULL) != 0)
		{
			write(2, "Error: Mutext Init has failed\n", 31);
			while (i >= 0)
			{
				pthread_mutex_destroy(&philo[i].l_fork);
				i--;
			}
			pthread_mutex_destroy(&data->exit);
			exit_program(data, philo);
		}
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		if (i == data->num_philo - 1)
			philo[i].r_fork = philo[0].l_fork;
		else
			philo[i].r_fork = philo[i + 1].l_fork;
		i++;
	}
	
	//Thread Creation
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->thread_id[i], NULL, &routine, &philo[i]) != 0)
		{
			write(2, "Error: Thread Creation Failed!\n", 32);
			exit_program(data, philo);
		}
		i++;
	}
	
	//Thread Joining
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_join(data->thread_id[i], NULL) != 0)
		{
			write(2, "Error: Thread Joining Failed!\n", 31);
			exit_program(data, philo);
		}
		i++;
	}
	free(data->thread_id);
}

//Main BITCHES
int main(int argc, char *argv[])
{
	int	i;
	t_data *data;
	t_pedo *philo;
		
	if (argc != 5 && argc != 6)
		return (write(2, "Error: Not the right Arguments!\n", 33));
	data = malloc(sizeof(t_data));
	if (!data)
		return (write(2, "Error: Memory Allocation Failed\n", 33));
	ft_bzero(data, sizeof(*data));
	data->num_philo = ft_atoi(argv[1]);
	data->running = 1;
	philo = malloc(sizeof(t_pedo) * data->num_philo);
	if (!philo)
		return (write(2, "Error: Memory Allocation Failed\n", 33));
	data->philo = philo;
	i = 0;
	while (i < data->num_philo)
	{
		ft_bzero(&philo[i], sizeof(t_pedo));
		philo[i].philo_id = i + 1;
		philo[i].data = data;
		i++;
	}
	task_times(data, argv, argc);
	time_start(data, &data->time_stamp);
	setter(data, philo);
	return(0);
}
