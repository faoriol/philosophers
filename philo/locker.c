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

void	drop_fork(t_thread *thread)
{
	pthread_mutex_lock(thread->left_fork->fork_mutex);
	thread->left_fork->state = true;
	pthread_mutex_unlock(thread->left_fork->fork_mutex);
	pthread_mutex_lock(thread->right_fork->fork_mutex);
	thread->right_fork->state = true;
	pthread_mutex_unlock(thread->right_fork->fork_mutex);
}
