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

void	drop_fork(t_thread *thread)
{
	pthread_mutex_lock(thread->left_fork->fork_mutex);
	thread->left_fork->state = true;
	pthread_mutex_unlock(thread->left_fork->fork_mutex);
	pthread_mutex_lock(thread->right_fork->fork_mutex);
	thread->right_fork->state = true;
	pthread_mutex_unlock(thread->right_fork->fork_mutex);
}

bool	philo_eat(t_thread *thread)
{
	int	max;

	while (!check_fork(thread->left_fork))
		if (!simulation_check(thread))
			return (false);
	philo_take(thread);
	while (!check_fork(thread->right_fork))
		if (!simulation_check(thread))
			return (false);
	philo_take(thread);
	if (!simulation_check(thread))
		return (false);
	mutex_print(thread, "is eating", thread->infos->start_time);
	thread->meal++;
	thread->last_meal = get_time();
	max = get_max_meal(thread);
	if (thread->meal == max)
		add_table_meal(thread);
	if (!simulation_check(thread))
		return (false);
	ft_usleep(thread, thread->time_to_eat * 1000);
	drop_fork(thread);
	return (true);
}

bool	philo_think(t_thread *thread)
{
	if (!simulation_check(thread))
		return (false);
	mutex_print(thread, "is thinking", thread->infos->start_time);
	return (true);
}

bool	philo_sleep(t_thread *thread)
{
	while (!simulation_check(thread))
		return (false);
	mutex_print(thread, "is sleeping", thread->infos->start_time);
	ft_usleep(thread, thread->time_to_sleep * 1000);
	return (true);
}

void	philo_take(t_thread *thread)
{
	if (!simulation_check(thread))
		return ;
	mutex_print(thread, "has taken a fork", thread->infos->start_time);
}

void	philo_died(t_thread *thread)
{
	mutex_print(thread, "died", thread->infos->start_time);
}
