/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:04:10 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/10 23:04:10 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	simulation_check(t_thread *thread, int last_meal)
{
	pthread_mutex_lock(thread->infos->stop);
	if (thread->infos->philo_died)
	{
		pthread_mutex_unlock(thread->infos->stop);
		return (false);
	}
	if (get_time() - last_meal >= thread->infos->time_to_die)
	{
		usleep(thread->infos->time_to_die * 1000);
		philo_died(thread);
		pthread_mutex_unlock(thread->infos->stop);
		return (false);
	}
	if (thread->infos->philo_full == thread->infos->nb_philos)
	{
		pthread_mutex_unlock(thread->infos->stop);
		return (false);
	}
	pthread_mutex_unlock(thread->infos->stop);
	return (true);
}

void	*routine(void *arg)
{
	t_thread	*thread;
	int			meals;
	int			last_meal;

	thread = (t_thread *)arg;
	meals = 0;
	last_meal = get_time();
	if (thread->infos->nb_philos == 1)
	{
		pthread_mutex_lock(&thread->infos->forks[0]);
		usleep(thread->infos->time_to_die * 1000);
		pthread_mutex_unlock(&thread->infos->forks[0]);
		philo_died(thread);
		return (NULL);
	}
	while (simulation_check(thread, last_meal))
	{
		philo_eat(thread, &meals, &last_meal);
		philo_sleep(thread);
		philo_think(thread);
	}
	return (NULL);
}
