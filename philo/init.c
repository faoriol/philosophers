/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:48:10 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/10 22:48:10 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv, t_infos *infos)
{
	int	value;
	int	index;

	index = 0;
	if (argc < 5)
		clean_exit(infos, NULL, "error: missing arguments");
	while (argv[index])
	{
		value = ft_atol(argv[index++]);
		if (value < 0)
			clean_exit(infos, NULL, "error: negative value");
	}
}

void	collect_infos(int argc, char **argv, t_infos *infos)
{
	check_args(argc, argv, infos);
	infos->waiting_philo = 0;
	infos->philo_died = false;
	infos->start_time = get_time();
	infos->nb_philos = ft_atol(argv[1]);
	infos->time_to_die = ft_atol(argv[2]);
	infos->time_to_eat = ft_atol(argv[3]);
	infos->time_to_sleep = ft_atol(argv[4]);
	infos->full_meal = 0;
	if (argc == 6)
		infos->max_meals = ft_atol(argv[5]);
	else
		infos->max_meals = -1;
}

bool	init_mutex(t_infos *infos, t_fork **forks)
{
	int	index;

	(*forks) = malloc(sizeof(t_fork) * infos->nb_philos);
	if (!(*forks))
		return (false);
	index = 0;
	memset(*forks, 0, sizeof(t_fork));
	infos->stop_mutex = malloc(sizeof(pthread_mutex_t));
	infos->meal_mutex = malloc(sizeof(pthread_mutex_t));
	infos->print_mutex = malloc(sizeof(pthread_mutex_t));
	infos->wait_mutex = malloc(sizeof(pthread_mutex_t));
	infos->table_meal_mutex = malloc(sizeof(pthread_mutex_t));

	while (index < infos->nb_philos)
	{
		(*forks)[index].fork_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((*forks)[index].fork_mutex, NULL);
		index++;
	}
	pthread_mutex_init(infos->stop_mutex, NULL);
	pthread_mutex_init(infos->meal_mutex, NULL);
	pthread_mutex_init(infos->print_mutex, NULL);
	pthread_mutex_init(infos->wait_mutex, NULL);
	pthread_mutex_init(infos->table_meal_mutex, NULL);
	return (true);
}

bool	init_thread(t_thread *thread, t_infos *infos, t_fork *forks, char **argv)
{
	int			index;

	index = 0;
	while (index < infos->nb_philos)
	{
		thread[index].meal = 0;
		thread[index].nb = index + 1;
		thread[index].infos = infos;
		thread[index].left_fork = &forks[index];
		thread[index].right_fork = &forks[(index + 1) % infos->nb_philos];
		thread[index].left_fork->state = true;
		thread[index].right_fork->state = true;
		thread[index].nb_philos = ft_atol(argv[1]);
		thread[index].time_to_die = ft_atol(argv[2]);
		thread[index].time_to_eat = ft_atol(argv[3]);
		thread[index].time_to_sleep = ft_atol(argv[4]);
		index++;
	}
	return (true);
}
