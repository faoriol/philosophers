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
	(*last_meal) = time;
	usleep(thread->time_to_eat);
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
	usleep(thread->time_to_sleep);
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
