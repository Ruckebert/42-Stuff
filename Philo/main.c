/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:37:21 by aruckenb          #+#    #+#             */
/*   Updated: 2024/09/19 13:36:48 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

//Time Checker and Creation
void	time_start(t_data *data, long long  *time_stamp)
{
	struct	timeval time;
	
	if (gettimeofday(&time, NULL) == 1)
		exit(1);
	*time_stamp = (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000));
}
long long	time_current(t_data *data)
{
	struct	timeval time;
	long long current_time;
	
	if (gettimeofday(&time, NULL) == 1)
		exit(1);
	current_time = (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000)) - data->time_stamp;
	return (current_time);
}
void	time_current_death(t_pedo *philo, t_data *data)
{
	struct	timeval time;

	if (gettimeofday(&time, NULL) == 1)
		exit(1);
	philo->start_of_death = (((long long)time.tv_sec * 1000) + ((long long)time.tv_usec / 1000)) - data->time_stamp;
}

//Utils
void	exit_program(t_data *data, t_pedo *philo)
{
	exit(0);
	int i;

	i = 0;
	/*if (data->thread_id != NULL)
	{
		while (i < data->num_philo)
		{
			if (pthread_join(data->thread_id[i], NULL) != 0)
			{
				write(2, "Error: Thread Joining Failed!\n", 31);
				free(data->thread_id);
				if (philo)
					free(philo);
				free(data);
				return ;
			}
			i++;
		}
		free(data->thread_id);
	}*/
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&philo[i].lock);
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
	free(philo);
	free(data);
	exit(0);
}

void	philo_dead(t_data *data, t_pedo *philo)
{
	printf("%lld %d died\n", time_current(data), philo->philo_id);
	philo->alive_or_dead = 1;
	exit_program(data, philo);
}

void 	better_usleep(t_data *data, t_pedo *philo, int time)
{
	long long start_time;
	long long elasped_time;

	start_time = time_current(data);
	
	while (1)
	{
		elasped_time = time_current(data) - start_time;
		
		if ((time_current(data) - philo->start_of_death) >= data->death_time)//Early Death Checker
            philo_dead(data, philo);
		
		if (elasped_time >= time)
			break ; 
		usleep(10);
	}
}

void	dead_or_alive(t_pedo *philo)
{
	int i = 0;

	i++;
	while (i < philo->data->num_philo)
	{
		if (philo[i].alive_or_dead == 1)
			exit_program(philo->data, philo);
		i++;
	}
}

//Philo activites 
void	philo_full(t_data *data, t_pedo *philo)
{
	data->full_philos++;
	if (data->full_philos == data->num_philo)
	{
		write(1, "Philosophers are all Full!\n", 28); //temp
		exit(1);
	}
}

void	eating(t_data *data, t_pedo *philo)
{	
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
		philo_dead(data, philo);
	
	pthread_mutex_lock(&philo->lock);
	dead_or_alive(philo);
	printf("%lld %d is eating\n", time_current(data), philo->philo_id);
	usleep(data->eat_time);
	pthread_mutex_unlock(&philo->lock);
	
	philo->fin_eating = 1;
	philo->meals_eaten++;
	time_current_death(philo, data);
}

void	philo_sleep(t_data *data, t_pedo *philo)
{
	philo->thinking = 0;
	
	pthread_mutex_lock(&philo->lock);
	dead_or_alive(philo);
	printf("%lld %d is sleeping\n", time_current(data), philo->philo_id);
	//better_usleep(data, philo, data->sleep_time);
	usleep(data->sleep_time);
	pthread_mutex_unlock(&philo->lock);
	
	time_current(data);
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
		philo_dead(data, philo);
	philo->fin_eating = 0;
}

void	thinking(t_data *data, t_pedo *philo, int sleep_time)
{
	philo->thinking = 1;
	if ((time_current(data) - philo->start_of_death) >= data->death_time)
		philo_dead(data, philo);
	
	pthread_mutex_lock(&philo->lock);
	dead_or_alive(philo);
	printf("%lld %d is thinking\n", time_current(data), philo->philo_id);
	//better_usleep(data, philo, (data->sleep_time - sleep_time));
	usleep(data->eat_time - sleep_time);
	pthread_mutex_unlock(&philo->lock);
}

//Main rountine
void	*routine(void *arg)
{
	t_pedo *philo = (t_pedo *)arg;
	t_data *data = philo->data;

	if (data->num_philo == 1) 
	{
		thinking(data, philo, 50);
		philo_dead(data, philo);
	}
	philo->thinking = 0;
	time_current(data);
	time_current_death(philo, data);

	//Even
	if (data->num_philo % 2 == 0)
	{
		if (philo->philo_id % 2 == 1)
		{
			pthread_mutex_lock(&philo->fork);
			philo->thinking = 0;
			philo->fork_equip = 1;
			
			pthread_mutex_lock(&philo->lock);
			dead_or_alive(philo);
			printf("%lld %d has taken a fork\n", time_current(data), philo->philo_id);
			pthread_mutex_unlock(&philo->lock);
			
			pthread_mutex_lock(&philo->lock);
			dead_or_alive(philo);
			printf("%lld %d has taken a fork\n", time_current(data), philo->philo_id);
			pthread_mutex_unlock(&philo->lock);
			
			eating(data, philo);
			pthread_mutex_unlock(&philo->fork);
		}
		else
			thinking(data, philo, 50);
	}
	else
	{ //Odd
		if (philo->philo_id == data->num_philo)
			thinking(data, philo, -((data->eat_time * 2)/2));
		else if (philo->philo_id % 2 == 1)
		{
			pthread_mutex_lock(&philo->fork);
			philo->thinking = 0;
			philo->fork_equip = 1;
			
			pthread_mutex_lock(&philo->lock);
			dead_or_alive(philo);
			printf("%lld %d has taken a fork\n", time_current(data), philo->philo_id);
			pthread_mutex_unlock(&philo->lock);
			
			pthread_mutex_lock(&philo->lock);
			dead_or_alive(philo);
			printf("%lld %d has taken a fork\n", time_current(data), philo->philo_id);
			pthread_mutex_unlock(&philo->lock);
			
			eating(data, philo);
			pthread_mutex_unlock(&philo->fork);
		}
		else
			thinking(data, philo, 50);

	}
	
	while (1)
	{	
		time_current(data);
		if ((time_current(data) - philo->start_of_death) >= data->death_time)//Early Death Checker
            philo_dead(data, philo);
		if (data->must_eat_time != 0 && philo->meals_eaten == data->must_eat_time) //Meals eaten
			philo_full(data, philo);
		if (philo->fin_eating == 1) //Sleeping 
			philo_sleep(data, philo);
	
		//Thinking
		if (philo->thinking == 0 || (philo->thinking == 0 && (philo->fin_eating == 1 || philo->fork_equip == 1)))	
			thinking(data, philo, 50); 

		pthread_mutex_lock(&philo->fork);
		if (philo->fin_eating == 0)
		{
			philo->thinking = 0;
			philo->fork_equip = 1;
			
			pthread_mutex_lock(&philo->lock);
			dead_or_alive(philo);
			printf("%lld %d has taken a fork\n", time_current(data), philo->philo_id);
			pthread_mutex_unlock(&philo->lock);
			
			pthread_mutex_lock(&philo->lock);
			dead_or_alive(philo);
			printf("%lld %d has taken a fork\n", time_current(data), philo->philo_id);
			pthread_mutex_unlock(&philo->lock);
			
			eating(data, philo);
		}
		pthread_mutex_unlock(&philo->fork);
	}
	return (0);
}

//Saving the times of the tasks
void	task_times(t_data *data, char *argv[], int argc)
{
	data->death_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]) * 1000;
	data->sleep_time = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data->must_eat_time = ft_atoi(argv[5]);
}

//Odd and even to be work on
void	setter(t_data *data, t_pedo *philo)
{
	int i;
	
	i = 0;
	//Creating the seperate thread IDS
	data->thread_id = malloc(sizeof(pthread_t) * data->num_philo);
	if (!data->thread_id)
	{
		write(2, "Error: Memory Allocation Failed\n", 33);
		return ;
	}
	//Mutex Creation
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&philo[i].lock, NULL) != 0)
		{
			write(2, "Error: Mutext Init has failed\n", 31);
			return ;
		}
		if (pthread_mutex_init(&philo[i].fork, NULL) != 0)
		{
			write(2, "Error: Mutext Init has failed\n", 31);
			return ;
		}
		i++;
	}
	//Thread Creation
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->thread_id[i], NULL, &routine, &philo[i]) != 0)
		{
			write(2, "Error: Thread Creation Failed!\n", 32);
			free(data->thread_id);
			return ;
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
			free(data->thread_id);
			return ;
		}
		i++;
	}
	free(data->thread_id);
}

//Main BITCHES
int main(int argc, char *argv[])
{
	int	i;
	t_data data;
	t_pedo *philo;
		
	if (argc != 5 && argc != 6)
		return (write(2, "Error: Not the right Arguments!\n", 33));
	ft_bzero(&data, sizeof(data));
	data.num_philo = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_pedo) * data.num_philo);
	if (!philo)
		return (write(2, "Error: Memory Allocation Failed\n", 33));
	data.philo = philo;
	i = 0;
	while (i < data.num_philo)
	{
		ft_bzero(&philo[i], sizeof(t_pedo));
		philo[i].philo_id = i + 1;
		philo[i].data = &data;
		i++;
	}
	task_times(&data, argv, argc);
	time_start(&data, &data.time_stamp);
	setter(&data, philo);
}

//Sleep function holds the thread
//You might have to change everything to writes but we will see
// IDk if this is gonna work by try phtead_t thread_id[ft_atoi(argv[1])]
//Thread share the same memories 
// Usleep causes the program to sleep for a couple of microseconds
// the function input can use the different nums of philo
// pthread_mutext_init(&mutext) creates a mutex
// phtread mutext destory() destories the mutex
// phread_mutex_lock(&mutex) sets the mutex to lock
// phread_mutex_unlock(&mutex) unlocks the mutex
//I need to create mutlipe threads for each philo idk whether to use a array with a while loop or simply add the number as an increasing value
// IDK if we need to store the amount of forks being used
