/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:30:00 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/10 22:30:00 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_thread *thread, int *meals, int *last_meal)
{
	int	time;

	lock(thread);
	philo_take(thread);
	time = get_time();
	printf("%d %d is eating\n", time, thread->nb);
	pthread_mutex_lock(thread->infos->meal_mutex);
	(*meals)++;
	(*last_meal) = time;
	if ((*meals) == thread->infos->max_meals && (*meals) != 0)
	{
		pthread_mutex_lock(thread->infos->stop);
		thread->infos->philo_full++;
		pthread_mutex_unlock(thread->infos->stop);
	}
	pthread_mutex_unlock(thread->infos->meal_mutex);
	usleep(thread->infos->time_to_eat * 1000);
	unlock(thread);
}

void	philo_think(t_thread *thread)
{
	int	time;

	time = get_time();
	printf("%d %d is thinking\n", time, thread->nb);
}

void	philo_sleep(t_thread *thread)
{
	int	time;

	time = get_time();
	printf("%d %d is sleeping\n", time, thread->nb);
	usleep(thread->infos->time_to_sleep * 1000);
}

void	philo_take(t_thread *thread)
{
	int	time;

	time = get_time();
	printf("%d %d has taken a fork\n", time, thread->nb);
	printf("%d %d has taken a fork\n", time, thread->nb);
}

void	philo_died(t_thread *thread)
{
	int	time;

	time = get_time();
	printf("%d %d died\n", time, thread->nb);
}
