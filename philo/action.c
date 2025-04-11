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

	time = get_time();
	printf("%d %d is eating\n", time, thread->nb);
	(*meals)++;
	if ((*meals) == thread->infos->max_meals && (*meals) != 0)
		thread->infos->philo_full++;
	(*last_meal) = time;
	usleep(thread->infos->time_to_eat * 1000);
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
}

void	philo_died(t_thread *thread)
{
	int	time;

	time = get_time();
	printf("%d %d died\n", time, thread->nb);
}
