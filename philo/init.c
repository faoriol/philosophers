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

bool	check_args(int argc, char **argv)
{
	int	value;
	int	index;

	index = 1;
	if (argc != 5 && argc != 6)
	{
		printf("error: ./philo ");
		printf("nb time_to_die time_to_eat time_to_sleep \"max_meals\"\n");
		return (false);
	}
	while (argv[index])
	{
		value = ft_atol(argv[index]);
		if (value <= 0)
		{
			printf("error: negative or null arguments value\n");
			return (false);
		}
		index++;
	}
	return (true);
}

bool	collect_infos(int argc, char **argv, t_infos *infos)
{
	if (!check_args(argc, argv))
	{
		free(infos);
		return (false);
	}
	infos->waiting_philo = false;
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
	return (true);
}

bool	init_mutex(t_infos *infos, t_fork **forks)
{
	int	index;

	index = 0;
	(*forks) = malloc(sizeof(t_fork) * infos->nb_philos);
	if (!(*forks))
		return (false);
	memset((*forks), 0, sizeof(t_fork) * infos->nb_philos);
	while (index < infos->nb_philos)
	{
		if (pthread_mutex_init(&(*forks)[index++].fork_mutex, NULL))
			return (false);
	}
	if (pthread_mutex_init(&infos->stop_mutex, NULL) != 0
		|| pthread_mutex_init(&infos->meal_mutex, NULL) != 0
		|| pthread_mutex_init(&infos->print_mutex, NULL) != 0
		|| pthread_mutex_init(&infos->wait_mutex, NULL) != 0
		|| pthread_mutex_init(&infos->table_meal_mutex, NULL) != 0)
		return (false);
	return (true);
}

bool	init_thread(t_thread *thread,
	t_infos *infos, t_fork *forks, char **argv)
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
