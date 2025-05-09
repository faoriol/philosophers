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
	return ((tv.tv_sec * 1000) + (unsigned int)(tv.tv_usec * 0.001));
}

void	drop_fork(t_thread *thread, pthread_mutex_t *left,
		pthread_mutex_t *right)
{
	pthread_mutex_lock(left);
	thread->left_fork->state = true;
	pthread_mutex_unlock(left);
	pthread_mutex_lock(right);
	thread->right_fork->state = true;
	pthread_mutex_unlock(right);
}

bool	mutex_print(t_thread *thread, char *msg, int start_time, t_infos *infos)
{
	pthread_mutex_lock(&infos->print_mutex);
	if (get_is_philo_died(&infos->stop_mutex, &infos->philo_died))
	{
		pthread_mutex_unlock(&infos->print_mutex);
		return (false);
	}
	printf("%d %d %s\n", get_time() - start_time, thread->nb, msg);
	pthread_mutex_unlock(&infos->print_mutex);
	return (true);
}

void	ft_usleep(long time_to, pthread_mutex_t *stop, bool *died)
{
	int	time;

	time = get_time();
	while ((get_time() - time) < (time_to * 0.001))
	{
		if (get_is_philo_died(stop, died))
			return ;
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
