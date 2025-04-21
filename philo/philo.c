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

bool	simulation_check(t_thread *thread)
{
	int		table_meal;

	pthread_mutex_lock(thread->infos->stop_mutex);
	if (thread->infos->philo_died == true)
	{
		pthread_mutex_unlock(thread->infos->stop_mutex);
		return (false);
	}
	if (get_time() - thread->last_meal > thread->time_to_die)
	{
		philo_died(thread);
		thread->infos->philo_died = true;
		pthread_mutex_unlock(thread->infos->stop_mutex);
		return (false);
	}
	table_meal = get_table_meal(thread);
	if (table_meal == thread->nb_philos)
	{
		thread->infos->philo_died = true;
		pthread_mutex_unlock(thread->infos->stop_mutex);
		return (false);
	}
	pthread_mutex_unlock(thread->infos->stop_mutex);
	return (true);
}

void	*routine(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *)arg;
	thread->last_meal = get_time();
	while (get_seated_philo(thread) == false)
		;
	if (thread->nb % 2 == 1)
		usleep(thread->time_to_eat / 2);
	while (simulation_check(thread))
	{
		if (!philo_eat(thread))
			break ;
		if (!philo_sleep(thread))
			break ;
		if (!philo_think(thread))
			break ;
	}
	return (NULL);
}
