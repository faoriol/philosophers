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

bool	simulation_check(t_thread *thread, int meals, int last_meal)
{
	pthread_mutex_lock(thread->infos->dead);
	if (thread->infos->philo_died == true)
	{
		pthread_mutex_unlock(thread->infos->dead);
		return (false);
	}
	pthread_mutex_unlock(thread->infos->dead);
	if (get_time() - last_meal > thread->time_to_die)
	{
		philo_died(thread);
		return (false);
	}
	if (meals == thread->max_meals)
	{
		printf("meals are epuised\n");
		return (false);
	}
	return (true);
}

void	*routine(void *arg)
{
	t_thread	*thread;
	int			meals;
	int			last_meal;

	thread = (t_thread *)arg;
	meals = 0;
	last_meal = 0;
	while (simulation_check(thread, meals, last_meal))
	{
		lock(thread);
		philo_take(thread);
		philo_eat(thread, &meals, &last_meal);
		unlock(thread);
		philo_sleep(thread);
		philo_think(thread);
	}
	return (0);
}
