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

bool	philo_eat(t_thread *thread, t_infos *infos, pthread_mutex_t *stop)
{
	int	max;

	while (!check_fork(thread, thread->left_fork))
		if (!simulation_check(thread, stop, &infos->philo_died))
			return (false);
	while (!check_fork(thread, thread->right_fork))
		if (!simulation_check(thread, stop, &infos->philo_died))
			return (false);
	if (!mutex_print(thread, "is eating", infos->start_time, infos))
		return (false);
	thread->meal++;
	thread->last_meal = get_time();
	max = get_max_meal(&infos->meal_mutex, &infos->max_meals);
	if (thread->meal == max)
		add_table_meal(thread);
	ft_usleep(thread->time_to_eat * 1000, stop, &infos->philo_died);
	if (!simulation_check(thread, stop, &infos->philo_died))
		return (false);
	drop_fork(thread, &thread->left_fork->fork_mutex,
		&thread->right_fork->fork_mutex);
	return (true);
}

bool	philo_think(t_thread *thread)
{
	if (!mutex_print(thread, "is thinking", thread->infos->start_time,
			thread->infos))
		return (false);
	return (true);
}

bool	philo_sleep(t_thread *thread, t_infos *infos)
{
	if (!mutex_print(thread, "is sleeping", infos->start_time,
			infos))
		return (false);
	ft_usleep(thread->time_to_sleep * 1000,
		&infos->stop_mutex, &infos->philo_died);
	return (true);
}

void	philo_died(t_thread *thread)
{
	pthread_mutex_lock(&thread->infos->print_mutex);
	printf("%d %d died\n", get_time() - thread->infos->start_time, thread->nb);
	pthread_mutex_unlock(&thread->infos->print_mutex);
}
