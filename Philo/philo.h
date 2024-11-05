/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:46:21 by aruckenb          #+#    #+#             */
/*   Updated: 2024/11/05 15:25:14 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_pedo
{
	t_data			*data;

	/*Philo ID and Death Start*/
	int				philo_id;
	long long		start_of_death;
	int				task_done;

	/*Activites*/
	int				fin_eating;
	int				thinking;
	int				meals_eaten;
	int				alive_or_dead;

	/*Forks*/
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;

}	t_pedo;

typedef struct s_data
{
	t_pedo			*philo;

	/*Philo Data*/
	int				num_philo;
	long long		time_stamp;
	int				full_philos;

	/*Philo times*/
	long long		death_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat_time;
	int				think_time;

	/*Threads and Mutex*/
	pthread_t		*thread_id;
	pthread_mutex_t	exit;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	print_lock_thinking;
	pthread_mutex_t	dead_or_alive_lock;
	pthread_mutex_t	full_lock;

}	t_data;

/*Time Functions*/
void		time_start(long long *time_stamp);
long long	time_current(t_data *data);
void		time_current_death(t_pedo *philo, t_data *data);
int			task_times(t_data *data, char *argv[], int argc);

/*Utils Functions*/
char		*ft_itoa(int n);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
int			write_message(t_data *data, t_pedo *philo, char *message);
void		philo_dead(t_data *data, t_pedo *philo);
void		philo_assign(t_pedo *philo, t_data *data);
int			better_usleep(t_data *data, t_pedo *philo, int time,
				int lock_or_fork);
int			dead_or_alive(t_pedo *philo, t_data *data, int lock_or_fork);
void		odd_forks_unlock(t_pedo *philo);
void		even_forks_unlock(t_pedo *philo);
void		free_all_data(t_data *data);
int			number_of_philo(t_data *data, char *argv[]);

/*Mutex & Thread Functions*/
int			mutex_creator(t_data *data);
int			fork_mutex(t_data *data, t_pedo *philo, int i);
void		assign_right_fork(t_data *data, t_pedo *philo);
int			thread_creation(t_data *data, t_pedo *philo, int i);

/*Philo Routine*/
void		*routine(void *arg);
void		solo_philo(t_data *data, t_pedo *philo);
int			even(t_data *data, t_pedo *philo);
int			odd(t_data *data, t_pedo *philo);
int			even_start(t_data *data, t_pedo *philo);
int			odd_start(t_data *data, t_pedo *philo);

/*Philo Activites*/
int			philo_full(t_data *data, t_pedo *philo);
int			eating(t_data *data, t_pedo *philo, int even_or_odd);
int			philo_sleep(t_data *data, t_pedo *philo);
int			thinking(t_data *data, t_pedo *philo, int time);

#endif
