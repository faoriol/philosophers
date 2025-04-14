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
	infos->philo_died = false;
	infos->philo_full = 0;
	infos->nb_philos = ft_atol(argv[1]);
	infos->time_to_die = ft_atol(argv[2]);
	infos->time_to_eat = ft_atol(argv[3]);
	infos->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		infos->max_meals = ft_atol(argv[5]);
	else
		infos->max_meals = -1;
}

void	init_mutex(t_infos *infos)
{
	int	index;

	index = 0;
	infos->forks = malloc(sizeof(pthread_mutex_t) * infos->nb_philos);
	if (!infos->forks)
		clean_exit(NULL, NULL, NULL);
	infos->stop = malloc(sizeof(pthread_mutex_t));
	if (!infos->stop)
		clean_exit(infos->forks, infos, NULL);
	infos->meal_mutex = malloc(sizeof(pthread_mutex_t));
	if (!infos->meal_mutex)
		clean_exit(infos->forks, infos, NULL);
	while (index < infos->nb_philos)
		pthread_mutex_init(&infos->forks[index++], NULL);
	pthread_mutex_init(infos->stop, NULL);
	pthread_mutex_init(infos->meal_mutex, NULL);
}

void	init_thread(t_thread *thread, t_infos *infos)
{
	int			index;

	index = 0;
	while (index < infos->nb_philos)
	{
		thread[index].nb = index;
		thread[index].infos = infos;
		thread[index].left_fork = &infos->forks[index];
		thread[index].right_fork = &infos->forks[(index + 1) % infos->nb_philos];
		index++;
	}
}
