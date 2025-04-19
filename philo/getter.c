/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol < faoriol@student.42lyon.fr >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:28:10 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/19 14:46:32 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_max_meal(t_thread *thread)
{
	int	value;

	pthread_mutex_lock(thread->infos.meal_mutex);
	value = thread->infos.max_meals;
	pthread_mutex_unlock(thread->infos.meal_mutex);
	return (value);
}

int	get_seated_philo(t_thread *thread)
{
	int	value;

	pthread_mutex_lock(thread->infos.wait_mutex);
	value = thread->infos.waiting_philo;
	pthread_mutex_unlock(thread->infos.wait_mutex);
	return (value);
}

int	get_is_philo_died(t_thread *thread)
{
	int	value;

	pthread_mutex_lock(thread->infos.stop_mutex);
	value = thread->infos.philo_died;
	pthread_mutex_unlock(thread->infos.stop_mutex);
	return (value);
}
