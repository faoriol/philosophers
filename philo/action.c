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

void	philo_eat(t_thread *thread)
{
	lock(thread);
	mutex_print(thread, "is eating", thread->infos.start_time);
	pthread_mutex_lock(thread->infos.meal_mutex);
	thread->meal++;
	thread->last_meal = get_time();
	pthread_mutex_unlock(thread->infos.meal_mutex);
	usleep(thread->time_to_eat * 1000);
	unlock(thread);
}

void	philo_think(t_thread *thread)
{
	mutex_print(thread, "is thinking", thread->infos.start_time);
}

void	philo_sleep(t_thread *thread)
{
	mutex_print(thread, "is sleeping", thread->infos.start_time);
	usleep(thread->time_to_sleep * 1000);
}

void	philo_take(t_thread *thread)
{
	mutex_print(thread, "has taken a fork", thread->infos.start_time);
}

void	philo_died(t_thread *thread)
{
	mutex_print(thread, "died", thread->infos.start_time);
	pthread_mutex_lock(thread->infos.stop_mutex);
	thread->infos.philo_died = true;
	pthread_mutex_unlock(thread->infos.stop_mutex);
}
