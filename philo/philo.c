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
	int		max;
	bool	died;

	died = get_is_philo_died(thread);
	if (died)
		return (false);
	if (get_time() - thread->last_meal >= thread->time_to_die)
	{
		philo_died(thread);
		return (false);
	}
	max = get_max_meal(thread);
	if (thread->meal == max)
		return (false);
	return (true);
}

// int	wait_threads(t_thread *thread)
// {
// 	int			seated;

// 	seated = get_seated_philo(thread);
// 	if (seated != thread->nb_philos)
// 		return (0);
// 	return (1);
// }

void	*routine(void *arg)
{
	t_thread	*thread;
	// int			add_ready;

	thread = (t_thread *)arg;
	thread->last_meal = get_time();
	// add_ready = get_seated_philo(thread) + 1;
	// set_waiting_philo(thread, &add_ready);
	// while (!wait_threads(thread))
		// ;
	while (simulation_check(thread))
	{
		philo_eat(thread);
		philo_sleep(thread);
		philo_think(thread);
	}
	return (NULL);
}
