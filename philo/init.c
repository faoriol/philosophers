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

void	check_args(int argc, char **argv)
{
	int	value;
	int	index;

	index = 0;
	if (argc < 5)
		clean_exit(NULL, "error: missing arguments");
	while (argv[index])
	{
		value = ft_atol(argv[index++]);
		if (value < 0)
			clean_exit(NULL, "error: negative value");
	}
}

void	collect_infos(int argc, char **argv, t_infos *infos)
{
	check_args(argc, argv);
	infos->nb_philos = ft_atol(argv[1]);
	infos->time_to_die = ft_atol(argv[2]);
	infos->time_to_eat = ft_atol(argv[3]);
	infos->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		infos->max_meals = ft_atol(argv[5]);
	else
		infos->max_meals = -1;
}

void	set_value(t_infos *infos, t_thread **thread)
{
	int	index;

	index = 0;
	while (index < infos->nb_philos)
	{
		(*thread)[index].time_to_die = infos->time_to_die;
		(*thread)[index].time_to_eat = infos->time_to_eat;
		(*thread)[index].time_to_sleep = infos->time_to_sleep;
		(*thread)[index].max_meals = infos->max_meals;
		index++;
	}
}

void	init_thread(t_infos *infos, t_thread **thread)
{
	int	index;

	index = 0;
	(*thread) = malloc(sizeof(t_thread) * infos->nb_philos);
	if (!(*thread))
		exit(EXIT_FAILURE);
	set_value(infos, &(*thread));
	while (index < infos->nb_philos)
	{
		if (pthread_create(&(*thread)[index].philo, NULL, &routine, &(*thread)[index]) != 0)
			clean_exit(*thread, "error: pthread_create failed");
		index++;
	}
	index = 0;
	while (index < infos->nb_philos)
	{
		if (pthread_join((*thread)[index].philo, NULL) != 0)
			clean_exit(*thread, "error: pthread_create failed");
		index++;
	}
}
