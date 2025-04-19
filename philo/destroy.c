/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol < faoriol@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:52:32 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/19 17:05:26 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutexes(t_infos *infos, t_fork *forks, int nb_philo)
{
	int	i;

	i = 0;
	if (infos)
	{
		pthread_mutex_destroy(infos->stop_mutex);
		pthread_mutex_destroy(infos->wait_mutex);
		pthread_mutex_destroy(infos->meal_mutex);
		pthread_mutex_destroy(infos->print_mutex);
		free(infos->stop_mutex);
		free(infos->wait_mutex);
		free(infos->meal_mutex);
		free(infos->print_mutex);
	}
	if (forks)
	{
		while (i < nb_philo)
		{
			pthread_mutex_destroy(forks[i].fork_mutex);
			free(forks[i].fork_mutex);
			i++;
		}
		free(forks);
	}
}

void	free_all(t_thread *threads, t_infos *infos, t_fork *forks)
{
	free_mutexes(infos, forks, threads->nb_philos);
	if (infos)
		free(infos);
	if (threads)
		free(threads);
}
