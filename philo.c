/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:11:46 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/09 19:11:46 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_exit(void *data, char *msg)
{
	if (data)
		free(data);
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

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

int	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*routine(void *arg)
{
	int			index;
	t_thread	*thread;

	thread = (t_thread *)arg;

	index = 0;
	while (index <= 42)
	{
		printf("time : %d thread : %ld -> %d\n", get_time(), thread->philo, index);
		index++;
		usleep(50000);
	}
	return (0);
}

void	init_thread(t_infos *infos, t_thread **thread)
{
	int	index;

	index = 0;
	(*thread) = malloc(sizeof(t_thread) * infos->nb_philos);
	if (!(*thread))
		exit(EXIT_FAILURE);
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

int	main(int argc, char **argv)
{
	t_infos		infos;
	t_thread	*thread;

	thread = NULL;
	collect_infos(argc, argv, &infos);
	init_thread(&infos, &thread);
	free(thread);
	return (EXIT_SUCCESS);
}
