/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faoriol <faoriol@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:48:39 by faoriol           #+#    #+#             */
/*   Updated: 2025/04/10 22:48:39 by faoriol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	drop_fork(t_thread *thread)
{
	pthread_mutex_lock(thread->left_fork->fork_mutex);
	thread->left_fork->state = true;
	pthread_mutex_unlock(thread->left_fork->fork_mutex);
	pthread_mutex_lock(thread->right_fork->fork_mutex);
	thread->right_fork->state = true;
	pthread_mutex_unlock(thread->right_fork->fork_mutex);
}

void	mutex_print(t_thread *thread, char *msg, int start_time)
{
	pthread_mutex_lock(thread->infos->print_mutex);
	printf("%d %d %s\n", get_time() - start_time, thread->nb, msg);
	pthread_mutex_unlock(thread->infos->print_mutex);
}

void	ft_usleep(t_thread *thread, long time_to)
{
	int	time;

	time = get_time();
	while ((get_time() - time) < (time_to / 1000))
	{
		if (!simulation_check(thread))
			return ;
		else
			usleep(10);
	}
}

void	*safe_alloc(size_t size, bool *check)
{
	void	*data;

	data = malloc(size);
	if (!data)
	{
		(*check) = false;
		return (NULL);
	}
	memset(data, 0, size);
	return (data);
}
