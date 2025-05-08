/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol < faoriol@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:28:10 by faoriol           #+#    #+#             */
/*   Updated: 2025/05/08 17:18:11 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_max_meal(pthread_mutex_t *meal, int *max_meals)
{
	int	value;

	pthread_mutex_lock(meal);
	value = (*max_meals);
	pthread_mutex_unlock(meal);
	return (value);
}

int	get_seated_philo(pthread_mutex_t *wait, int *waiting_philo)
{
	int	value;

	pthread_mutex_lock(wait);
	value = (*waiting_philo);
	pthread_mutex_unlock(wait);
	return (value);
}

int	get_is_philo_died(pthread_mutex_t *stop, bool *philo_died)
{
	int	value;

	pthread_mutex_lock(stop);
	value = (*philo_died);
	pthread_mutex_unlock(stop);
	return (value);
}

int	get_table_meal(pthread_mutex_t *table, int *full_meal)
{
	int	value;

	pthread_mutex_lock(table);
	value = (*full_meal);
	pthread_mutex_unlock(table);
	return (value);
}

int	check_fork(t_thread *thread, t_fork *fork)
{
	pthread_mutex_lock(&fork->fork_mutex);
	if (fork->state == true)
	{
		fork->state = false;
		pthread_mutex_unlock(&fork->fork_mutex);
		if (!mutex_print(thread, "has taken a fork", thread->infos->start_time,
				thread->infos))
			return (0);
		return (1);
	}
	pthread_mutex_unlock(&fork->fork_mutex);
	return (0);
}
