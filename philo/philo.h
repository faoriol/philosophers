/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:56:42 by faoriol           #+#    #+#             */
/*   Updated: 2025/02/01 00:56:42 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct s_fork
{
	bool			state;
	pthread_mutex_t	fork_mutex;
}				t_fork;

typedef struct s_infos
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				full_meal;
	bool			philo_died;
	int				start_time;
	bool			waiting_philo;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	table_meal_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	wait_mutex;
}				t_infos;

typedef struct s_thread
{
	t_infos			*infos;
	int				nb;
	int				meal;
	pthread_t		philo;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				last_meal;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}				t_thread;

/* action.c */
bool	philo_eat(t_thread *thread);
bool	philo_think(t_thread *thread);
bool	philo_sleep(t_thread *thread);
void	philo_take(t_thread *thread);
void	philo_died(t_thread *thread);

/* atol.c */
long	ft_atol(const char *str);

/* destroy.c */
void	clean_exit(void *data, void *data2, char *msg);
int		free_all(t_thread *threads, t_infos *infos, t_fork *forks, int code);
void	free_mutexes(t_infos *infos, t_fork *forks, int nb_philo);
void	destroy_mutexes(t_infos *infos, t_fork *forks, int nb_philo);

/* getter.c */
int		get_table_meal(t_thread *thread);
int		get_max_meal(t_thread *thread);
int		get_seated_philo(t_thread *thread);
int		get_is_philo_died(t_thread *thread);
int		check_fork(t_fork *fork);

/* init.c */
bool	check_args(int argc, char **argv);
bool	collect_infos(int argc, char **argv, t_infos *infos);
bool	init_mutex(t_infos *infos, t_fork **forks);
bool	init_thread(t_thread *thread,
			t_infos *infos, t_fork *forks, char **argv);

/* main.c */
bool	start_thread(t_thread *thread);

/* philo.c */
bool	simulation_check(t_thread *thread);
void	*routine(void *arg);

/* setter.c */
void	add_table_meal(t_thread *thread);
void	set_waiting_philo(t_thread *thread);
void	set_dead_mutex(t_thread *thread);

/* utils.c */
int		get_time(void);
void	mutex_print(t_thread *thread, char *msg, int last_meal);
void	ft_usleep(t_thread *thread, long time_to);
void	*safe_alloc(size_t size, bool *check);
void	drop_fork(t_thread *thread);

#endif
