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
		pthread_mutex_lock(thread->left_fork);
		pthread_mutex_lock(thread->right_fork);
	}
	else
	{
		pthread_mutex_lock(thread->right_fork);
		pthread_mutex_lock(thread->left_fork);
	}
}

void	unlock(t_thread *thread)
{
	pthread_mutex_unlock(thread->left_fork);
	pthread_mutex_unlock(thread->right_fork);
}
