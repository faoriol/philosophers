// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   philo.h                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/01 00:56:42 by faoriol           #+#    #+#             */
// /*   Updated: 2025/02/01 00:56:42 by faoriol          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

typedef struct	s_infos
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				philo_full;
	bool			philo_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*dead;
}				t_infos;

typedef struct	s_thread
{
	t_infos			*infos;
	int				nb;
	pthread_t		philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_thread;

void	philo_eat(t_thread *thread, int *meals, int *last_meal);
void	philo_think(t_thread *thread);
void	philo_sleep(t_thread *thread);
void	philo_take(t_thread *thread);
void	clean_exit(void *data, void *data2, char *msg);
void	check_args(int argc, char **argv, t_infos *infos);
void	collect_infos(int argc, char **argv, t_infos *infos);
int		get_time(void);
bool	simulation_check(t_thread *thread, int last_meal);
void	init_thread(t_thread *thread, t_infos *infos);
long	ft_atol(const char *str);
void	philo_died(t_thread *thread);
void	*routine(void *arg);
void	lock(t_thread *thread);
void	unlock(t_thread *thread);
void	init_mutex(t_infos *infos);

#endif
