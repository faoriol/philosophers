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
	thread->state = EATING;
	printf("%d %ld is eating\n", time, thread->philo);
	(*meals)++;
	(*last_meal) = time;
	usleep(thread->time_to_eat);
}

void	philo_think(t_thread *thread)
{
	int	time;

	time = get_time();
	thread->state = THINKING;
	printf("%d %ld is thinking\n", time, thread->philo);
}

void	philo_sleep(t_thread *thread)
{
	int	time;

	time = get_time();
	thread->state = SLEEPING;
	printf("%d %ld is sleeping\n", time, thread->philo);
	usleep(thread->time_to_sleep);
}

void	philo_take(t_thread *thread)
{
	int	time;

	time = get_time();
	thread->state = TAKING;
	printf("%d %ld has taken a fork\n", time, thread->philo);
}
