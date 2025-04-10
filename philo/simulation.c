/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:50:55 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/10 22:50:55 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	simulation_check(t_thread *thread, int meals, int last_meal)
{
	if (get_time() - last_meal < thread->time_to_die)
		return (false);
	if (thread->state == DYING)
		return (false);
	if (meals == thread->max_meals)
		return (false);
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
		philo_take(thread);
		philo_eat(thread, &meals, &last_meal);
		philo_sleep(thread);
		philo_think(thread);
	}
	return (0);
}
