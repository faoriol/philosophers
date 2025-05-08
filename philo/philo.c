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

bool	simulation_check(t_thread *thread, pthread_mutex_t *stop, bool *died)
{
	int		table_meal;

	table_meal = get_table_meal(&thread->infos->table_meal_mutex,
			&thread->infos->full_meal);
	pthread_mutex_lock(stop);
	if (table_meal == thread->nb_philos)
	{
		thread->infos->philo_died = true;
		pthread_mutex_unlock(stop);
		return (false);
	}
	else if (*died == true)
	{
		pthread_mutex_unlock(stop);
		return (false);
	}
	else if (get_time() - thread->last_meal > thread->time_to_die)
	{
		thread->infos->philo_died = true;
		pthread_mutex_unlock(stop);
		philo_died(thread);
		return (false);
	}
	pthread_mutex_unlock(stop);
	return (true);
}

void	*routine(void *arg)
{
	t_thread	*thread;
	t_infos		*infos;

	thread = (t_thread *)arg;
	infos = thread->infos;
	while (get_seated_philo(&infos->wait_mutex,
			&infos->waiting_philo) == false)
		usleep(100);
	if (thread->nb % 2 == 0)
		usleep((thread->time_to_eat * 1000) >> 1);
	thread->last_meal = get_time();
	while (simulation_check(thread, &infos->stop_mutex,
			&infos->philo_died))
	{
		if (!philo_eat(thread, infos, &infos->stop_mutex))
			break ;
		if (!philo_sleep(thread, infos))
			break ;
		if (!philo_think(thread))
			break ;
	}
	return (NULL);
}
