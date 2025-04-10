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

typedef enum	e_status
{
	EATING,
	THINKING,
	SLEEPING,
	TAKING,
	DYING
}			t_status;

typedef struct	s_infos
{
	int	nb_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}				t_infos;

typedef struct	s_thread
{
	t_status	state;
	pthread_t	philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			max_meals;
}				t_thread;

void	philo_eat(t_thread *thread, int *meals, int *last_meal);
void	philo_think(t_thread *thread);
void	philo_sleep(t_thread *thread);
void	philo_take(t_thread *thread);
void	clean_exit(void *data, char *msg);
void	check_args(int argc, char **argv);
void	collect_infos(int argc, char **argv, t_infos *infos);
int		get_time(void);
bool	simulation_check(t_thread *thread, int meals, int last_meal);
void	set_value(t_infos *infos, t_thread **thread);
void	init_thread(t_infos *infos, t_thread **thread);
long	ft_atol(const char *str);
void	*routine(void *arg);

#endif
