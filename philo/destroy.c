/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol < faoriol@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:52:32 by faoriol           #+#    #+#             */
/*   Updated: 2025/05/04 18:04:40 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_infos *infos, t_fork *forks, int nb_philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&infos->stop_mutex);
	pthread_mutex_destroy(&infos->wait_mutex);
	pthread_mutex_destroy(&infos->meal_mutex);
	pthread_mutex_destroy(&infos->print_mutex);
	pthread_mutex_destroy(&infos->table_meal_mutex);
	if (forks)
	{
		while (i < nb_philo)
			pthread_mutex_destroy(&forks[i++].fork_mutex);
	}
}

int	free_all(t_thread *threads, t_infos *infos, t_fork *forks, int code)
{
	if (forks)
	{
		destroy_mutexes(infos, forks, infos->nb_philos);
		free(forks);
	}
	if (infos)
		free(infos);
	if (threads)
		free(threads);
	return (code);
}
