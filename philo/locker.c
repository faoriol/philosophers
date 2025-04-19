/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:24:32 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/11 01:24:32 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock(t_thread *thread)
{
	if (thread->nb % 2 == 0)
	{
		pthread_mutex_lock(thread->left_fork->fork_mutex);
		pthread_mutex_lock(thread->right_fork->fork_mutex);
		thread->left_fork->state = false;
		philo_take(thread);
		thread->right_fork->state = false;
		philo_take(thread);
	}
	else
	{
		pthread_mutex_lock(thread->right_fork->fork_mutex);
		pthread_mutex_lock(thread->left_fork->fork_mutex);
		thread->left_fork->state = false;
		philo_take(thread);
		thread->right_fork->state = false;
		philo_take(thread);
	}
}

void	unlock(t_thread *thread)
{
	pthread_mutex_unlock(thread->left_fork->fork_mutex);
	pthread_mutex_unlock(thread->right_fork->fork_mutex);
	thread->left_fork->state = true;
	thread->right_fork->state = true;
}

int	getter(int value, pthread_mutex_t *mutex)
{
	int	i;

	pthread_mutex_lock(mutex);
	i = value;
	pthread_mutex_unlock(mutex);
	return (i);
}
